from django import forms
from .models import CustomUser
from allauth.account.forms import SignupForm
from .validators import validate_not_banned_username

class UserProfileForm(forms.ModelForm):
    class Meta:
        model = CustomUser
        fields = ['username', 'avatar']

class CustomSignupForm(SignupForm):
    username = forms.CharField(
        max_length=30,
        label="Username",
        # unique=True,
        validators=[validate_not_banned_username],
    )
    
    def save(self, request):
        user = super().save(request)
        return user