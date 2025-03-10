from django.urls import path, include
from .views import profile_update

urlpatterns = [
	path('accounts/', include('allauth.urls')),
	path('profile/edit/', profile_update, name='profile_edit'),
]