from django import forms
from .models import CustomUser
from allauth.account.forms import SignupForm
from .validators import validate_not_banned_username, validate_min_username_length
from django.utils.translation import gettext as _

class UserProfileForm(forms.ModelForm):
    class Meta:
        model = CustomUser
        fields = ['username', 'avatar']

class UsernameProfileForm(forms.ModelForm):
    class Meta:
        model = CustomUser
        fields = ['username']

class AvatarProfileForm(forms.ModelForm):
    class Meta:
        model = CustomUser
        fields = ['avatar']

class CustomSignupForm(SignupForm):
    username = forms.CharField(
        max_length=30,
        label=_("Username"),
        # unique=True,
        validators=[validate_not_banned_username, validate_min_username_length],
    )
    
    def save(self, request):
        user = super().save(request)
        return user