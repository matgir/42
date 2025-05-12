from django import forms
from users.models import CustomUser

class FortyTwoUsername(forms.ModelForm):
    class Meta:
        model = CustomUser
        fields = ['username']