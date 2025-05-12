# ---- Shorcuts -------------------------
from django.shortcuts import render, redirect
from django.urls import reverse

# ---- Authentication -------------------
from django.contrib.auth.models import User
from .models import FriendRequest, Notification

# ---- Forms ----------------------------
from .forms import (
    AvatarForm,
    UsernameForm,
    SearchUser,
    MFAForm
)

# ---- Decorators ----------------------
from django.contrib.auth.decorators import login_required
from django.views.decorators.cache import never_cache


# ---- Etc ------------------------------
from django.http import HttpResponseRedirect
from django.http import HttpResponse
from django.views.generic import TemplateView
from chat.models import Chat
from django.contrib.auth import logout as django_logout
from django.contrib.auth import login as django_login
from django.db.models import Q


# --- Utils -----------------------------
from chat.chat_utils import get_or_create_chat

from .utils.login_utils import (
    create_user,
    sign_in_strategy,
    sign_up_strategy,
    login_page
)
from .utils.social_utils import (
    send_friend_request,
    accept_friend_request,
    decline_friend_request,
    remove_friend,
    user_is_friend,
    cancel_friend_request,
    block_user,
    unblock_user,
    get_social_data,
    user_profile,
    has_received_friend_request,
    has_sent_friend_request,
    _is_friend_
)

# ---- Rest Framework JWT ---------------
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework.permissions import IsAuthenticated
from rest_framework_simplejwt.authentication import JWTAuthentication
from rest_framework.decorators import api_view, permission_classes

# --- Django-allauth MFA
from allauth.mfa.adapter import DefaultMFAAdapter

from django.urls import reverse
from django.shortcuts import redirect
from allauth.account.views import LogoutView
from django.contrib.auth.mixins import LoginRequiredMixin
from django.views import View

class Deactivate2FAView(LoginRequiredMixin, View):
    # Your view code for deactivating 2FA

    def get_success_url(self):
        # Specify where to redirect after deactivation
        return reverse('core:my_profile')  # Adjust the URL name as per your project setup


# ---- <login.html> ---------------------
def login(request):
    if DefaultMFAAdapter().is_mfa_enabled(request.user):
        print("MFA enabled")
    else:
        print("MFA disabled")
    if request.user.is_authenticated:
        return redirect("/home/")
    if request.method == "POST":
        if "signin-username" in request.POST:
            return sign_in_strategy(request)
        elif "signup-username" in request.POST:
            return sign_up_strategy(request)
        else:
            return HttpResponseRedirect(reverse('core:login'))
    else:
        return login_page(request)

def logout(request):
        django_logout(request)
        return redirect(reverse('core:login'))

def mfa(request):
    try:
        mfa_form = MFAForm(prefix='mfa')
        user_id = request.session.get("pending_user_id")
        user = User.objects.get(id=user_id)
        if request.method == "POST":
            mfa_form = MFAForm(request.POST, user=user, prefix="mfa")
            if mfa_form.is_valid():
                django_login(request, user, backend='django.contrib.auth.backends.ModelBackend')
                del request.session['pending_user_id']
                return HttpResponseRedirect("/home/")
        return render(request, "core/mfa.html", {
            "mfa_form": mfa_form
        })
    except Exception as e:
        return render(request, "core/500.html", {"exception": e})



# ---- <home.html> ----------------------
@login_required
@never_cache
def home(request):
    adapter = DefaultMFAAdapter()
    if adapter.is_mfa_enabled(request.user):
        print("MFA Enabled")
    else:
        print("MFA Disabled")
    chats = Chat.get_all_chats(request.user)
    for chat in chats:
        unread_messages = chat.message_set.order_by('createdAt').filter(isRead=False)
        readed_messages = chat.message_set.order_by('createdAt').filter(isRead=True)
        for unread_message in unread_messages:
            if unread_message.author != request.user:
                print(f"You have unread message : {unread_message.message} from {unread_message.author}")
                Notification.objects.get_or_create(
                    receiver=request.user,
                    message=unread_message
                )
        for readed_message in readed_messages:
            if readed_message.author != request.user.username:
                notification = Notification.objects.filter(message=readed_message).first()
                if notification:
                    notification.delete()

    notifications = request.user.notification_receiver.all()
    total_notifs     = 0

    for total_notifs in range(len(notifications)):
        total_notifs += 1

    context = {
        "notifications": notifications,
        "total_notifs": total_notifs,
    }

    message_to_user = request.session.pop('message_to_user', None)
    if message_to_user:
        context['message_to_user'] = message_to_user

    return render(request, "core/home.html", context)

@login_required
@never_cache
def my_profile(request):
    username_is_valid = True
    avatar_is_valid = True
    tmp_name = request.user.username
    username = tmp_name
    if request.method == "POST":
        # This form updates the existing UserProfile for the current user
        avatar_form = AvatarForm(request.POST, request.FILES, instance=request.user.userprofile, prefix="avatar")
        username_form = UsernameForm(request.POST, prefix="username", instance=request.user)
        # Check if username_form data is present in the request
        username_form_fields = any(key.startswith("username-") for key in request.POST.keys())
        if 'avatar-avatar' in request.FILES and avatar_form.is_valid():
            avatar_form.save()
            return HttpResponseRedirect("/my_profile/")
        elif 'avatar-avatar' in request.FILES and not avatar_form.is_valid():
            avatar_is_valid = False
        elif username_form_fields and username_form.is_valid():
            username_form.save()
            return HttpResponseRedirect("/my_profile/")
        elif username_form_fields and not username_form.is_valid():
            username_is_valid = False
            username = tmp_name
    avatar_form = AvatarForm(prefix="avatar")
    mfa_is_enabled = DefaultMFAAdapter().is_mfa_enabled(request.user)
    username_form = UsernameForm(prefix="username")
    avatar_url = request.user.userprofile.avatar.url
    return render(request, "core/my_profile.html", {
        "avatar_form": avatar_form,
        "username_form": username_form,
        "username_is_valid": username_is_valid,
        "avatar": avatar_url,
        "avatar_is_valid": avatar_is_valid,
        "mfa_is_enabled": mfa_is_enabled,
        "username": username
    })

# ---- <social.html> ---------------------------
@login_required
@never_cache
def profile(request, username):
    try:
        user_profile = User.objects.get(username=username)
        from_user = request.user.id
        to_user = user_profile.id
        is_friend = _is_friend_(request, user_profile)
        received_friend_request = has_received_friend_request(request, user_profile)
        sent_friend_request     = has_sent_friend_request(request, user_profile)
        chat = get_or_create_chat(request, user_profile)
        room_name = chat.id
        all_users = User.objects.all()
        blocked_by_thems = request.user.userprofile.blocked_by_them.all()
        blocked_by_mes = request.user.userprofile.blocked_by_me.all()
        is_blocked_by_them = False
        is_blocked_by_me = False
        for blocked_by_them in blocked_by_thems:
            if ( blocked_by_them == user_profile ):
                is_blocked_by_them = True
        for blocked_by_me in blocked_by_mes:
            if ( blocked_by_me == user_profile ):
                is_blocked_by_me = True
    except Exception as e:
        print(e)
        request.session['message_to_user'] = "User Does Not Exist"
        return redirect(reverse('core:home'))
    context = {
        "all_users": all_users,
        "user_profile": user_profile,
        "received_friend_request": received_friend_request,
        "sent_friend_request": sent_friend_request,
        "is_friend": is_friend,
        "is_blocked_by_me": is_blocked_by_me,
        "is_blocked_by_them": is_blocked_by_them,
        "room_name": room_name
    }

    return render(request, "core/user_profile.html", context)


@login_required
@never_cache
def social(request, searched_username="", user_found=True):

    context = get_social_data(request)
    search_user_form = SearchUser(prefix="search")
    if request.method == "POST":
        search_user_form = SearchUser(request.POST, prefix="search")
        if search_user_form.is_valid():
            return user_profile(request, search_user_form)
        else:
            return redirect("/home/")


    notification = request.session.pop('message_to_user', None)
    if notification:
        context['message_to_user'] = notification

    context['search_form'] = search_user_form
    context['user_found'] = user_found
    return render(request, "core/social.html", context)

@login_required
@never_cache
def notifications(request):
    notifications = request.user.notification_receiver.all()

    context = {
        "notifications": notifications
    }

    message_to_user = request.session.pop('message_to_user', None)
    if message_to_user:
        context['message_to_user'] = message_to_user

    return render(request, "core/notifications.html", context)
