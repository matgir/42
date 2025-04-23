from django.urls import path, include, re_path
from django.views.static import serve
from . import views
from django.contrib.auth import views as auth_views
from django.conf import settings
import os

# app_name = "users"

urlpatterns = [
	path('accounts/', include('allauth.urls')),
	path('profile/edit/', views.profile_update, name='profile_edit'),
	path('search/', views.search_friends, name='search_friends'),
	path('add-friend/<str:username>/', views.add_friend, name='add_friend'),
	path('remove-friend/<str:username>/', views.remove_friend, name='remove_friend'),
	path('profile', views.user_profile, name='user_profile'),
	path('user_profil/', views.user_profile, name='user_profil'),
	path('my_profile/', views.my_profile, name='my_profile'),
	path('my_friends/', views.friends_list, name='friends_list'),
	re_path(r'^three/(?P<path>.*)$', serve, {
        'document_root': os.path.join(settings.STATIC_ROOT, 'libs/three'),
    }),
    path('profil/', views.my_profile, name='my_profil'),
]
