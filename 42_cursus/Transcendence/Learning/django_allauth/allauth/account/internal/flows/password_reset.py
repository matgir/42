from urllib.parse import quote

from django.contrib import messages
from django.contrib.auth.models import AbstractBaseUser
from django.http import HttpRequest
from django.urls import reverse

from allauth.account import app_settings, signals
from allauth.account.adapter import get_adapter
from allauth.account.app_settings import LoginMethod
from allauth.account.internal.flows.signup import send_unknown_account_mail
from allauth.account.models import EmailAddress
from allauth.core.internal.httpkit import get_frontend_url
from allauth.utils import build_absolute_uri


def reset_password(user: AbstractBaseUser, password: str) -> None:
    get_adapter().set_password(user, password)


def finalize_password_reset(request: HttpRequest, user: AbstractBaseUser) -> None:
    adapter = get_adapter()
    if user:
        # User successfully reset the password, clear any
        # possible cache entries for all email addresses.
        for email in EmailAddress.objects.filter(user_id=user.pk):
            adapter._delete_login_attempts_cached_email(request, email=email.email)

    adapter.add_message(
        request,
        messages.SUCCESS,
        "account/messages/password_changed.txt",
    )
    signals.password_reset.send(
        sender=user.__class__,
        request=request,
        user=user,
    )
    adapter.send_notification_mail("account/email/password_reset", user)


def get_reset_password_url(request: HttpRequest) -> str:
    url = get_frontend_url(request, "account_reset_password")
    if not url:
        url = build_absolute_uri(request, reverse("account_reset_password"))
    return url


def get_reset_password_from_key_url(request: HttpRequest, key: str) -> str:
    """
    Method intented to be overriden in case the password reset email
    needs to point to your frontend/SPA.
    """
    url = get_frontend_url(request, "account_reset_password_from_key", key=key)
    if not url:
        # We intentionally accept an opaque `key` on the interface here, and not
        # implementation details such as a separate `uidb36` and `key. Ideally,
        # this should have done on `urls` level as well.
        path = reverse(
            "account_reset_password_from_key", kwargs={"uidb36": "UID", "key": "KEY"}
        )
        path = path.replace("UID-KEY", quote(key))
        url = build_absolute_uri(request, path)
    return url


def request_password_reset(request, email, users, token_generator):
    from allauth.account.utils import user_pk_to_url_str, user_username

    if not users:
        send_unknown_account_mail(request, email)
        return
    adapter = get_adapter()
    for user in users:
        temp_key = (
            token_generator or app_settings.PASSWORD_RESET_TOKEN_GENERATOR()
        ).make_token(user)

        # send the password reset email
        uid = user_pk_to_url_str(user)
        # We intentionally pass an opaque `key` on the interface here, and
        # not implementation details such as a separate `uidb36` and
        # `key. Ideally, this should have done on `urls` level as well.
        key = f"{uid}-{temp_key}"
        url = adapter.get_reset_password_from_key_url(key)
        context = {
            "user": user,
            "password_reset_url": url,
            "uid": uid,
            "key": temp_key,
            "request": request,
        }

        if LoginMethod.USERNAME in app_settings.LOGIN_METHODS:
            context["username"] = user_username(user)
        adapter.send_password_reset_mail(user, email, context)
