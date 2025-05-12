from django.urls import path, include, re_path
from django.views.static import serve
from . import views
from django.contrib.auth import views as auth_views
# from two_factor.views import LoginView as TwoFactorLoginView
from .views import CustomTwoFactorSetupView
from .views import CustomSetupCompleteView
from .views import CustomDisable2FAView
from .views import ConditionalLoginView
from .views import CustomSignupView
from .views import CustomLogoutView
from .views import CustomTwoFactorLoginView
from rest_framework_simplejwt.views import (
	TokenObtainPairView,
	TokenRefreshView,
	TokenVerifyView,
)

from django.conf import settings
import os

# app_name = "users"
urlpatterns = [
	path('accounts/two_factor/setup/', CustomTwoFactorSetupView.as_view(), name='two_factor_setup'),
	path('accounts/two_factor/setup/complete/', CustomSetupCompleteView.as_view(), name='two_factor_setup_complete'),
	path('accounts/two_factor/disable/', CustomDisable2FAView.as_view(), name='two_factor_disable'),
	path('accounts/two_factor/login/', CustomTwoFactorLoginView.as_view(), name='two_factor_login'),
	path('accounts/login/', ConditionalLoginView.as_view(), name='account_login'),
	path('profile_edit/', views.profile_update, name='profile_edit'),
	path('profile_avatar_edit/', views.profile_avatar_update, name='profile_avatar_edit'),
	path('search_friends/', views.search_friends, name='search_friends'),
	path('add-friend/', views.add_friend, name='add_friend'),
	path('remove-friend/', views.remove_friend, name='remove_friend'),
	path('accounts/signup/', CustomSignupView.as_view(), name='account_signup'),
	path('accounts/logout/', CustomLogoutView.as_view(), name='account_logout'),
	path('accounts/', include('allauth.urls')),
	path('profile/<str:username>/', views.user_profile, name='user_profile'),
	path('user_profil/', views.user_profile, name='user_profil'),
	path('my_profile/', views.my_profile, name='my_profile'),
	path('my_friends/', views.friends_list, name='friends_list'),
	path('profil/', views.my_profile, name='my_profil'),
	path('i18n/', include('django.conf.urls.i18n')),
	path('set_language/', views.set_language_and_remember, name='set_language_and_remember'),
		
	# JWT token endpoints
	path('token/', TokenObtainPairView.as_view(), name='token_obtain_pair'),
	path('token/refresh/', TokenRefreshView.as_view(), name='token_refresh'),
	path('token/verify/', TokenVerifyView.as_view(), name='token_verify'),

	re_path(r'^three/(?P<path>.*)$', serve, {
		'document_root': os.path.join(settings.STATIC_ROOT, 'libs/three'),
	}),
]
