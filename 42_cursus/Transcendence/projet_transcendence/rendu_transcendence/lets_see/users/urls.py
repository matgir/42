from django.urls import path, include, re_path
from django.views.static import serve
from . import views
from django.contrib.auth import views as auth_views
from two_factor.views import LoginView as TwoFactorLoginView
from .views import CustomTwoFactorSetupView
from .views import CustomSetupCompleteView
from .views import CustomDisable2FAView
from .views import ConditionalLoginView
# from .views import CustomTwoFactorLoginView


from django.conf import settings
import os

# app_name = "users"

urlpatterns = [
    path('accounts/two_factor/setup/', CustomTwoFactorSetupView.as_view(), name='two_factor_setup'),
    path('accounts/two_factor/setup/complete/', CustomSetupCompleteView.as_view(), name='two_factor_setup_complete'),
    path('accounts/two_factor/disable/', CustomDisable2FAView.as_view(), name='two_factor_disable'),
    path('accounts/login/', ConditionalLoginView.as_view(), name='account_login'),
	path('accounts/', include('allauth.urls')),
	path('profile_edit/', views.profile_update, name='profile_edit'),
	path('search_friends/', views.search_friends, name='search_friends'),
	path('add_friend/<str:username>/', views.add_friend, name='add_friend'),
	path('remove-friend/<str:username>/', views.remove_friend, name='remove_friend'),
	path('profile/<str:username>/', views.user_profile, name='user_profile'),
	path('user_profil/', views.user_profile, name='user_profil'),
	path('my_profile/', views.my_profile, name='my_profile'),
	path('my_friends/', views.friends_list, name='friends_list'),
	re_path(r'^three/(?P<path>.*)$', serve, {
        'document_root': os.path.join(settings.STATIC_ROOT, 'libs/three'),
    }),
    path('profil/', views.my_profile, name='my_profil'),
]
