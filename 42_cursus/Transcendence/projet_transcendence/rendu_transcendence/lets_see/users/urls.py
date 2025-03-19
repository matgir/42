from django.urls import path, include
from . import views
from django.contrib.auth import views as auth_views

# app_name = "users"

urlpatterns = [
	path('accounts/', include('allauth.urls')),
	path('profile/edit/', views.profile_update, name='profile_edit'),
	path('search/', views.search_friends, name='search_friends'),
	path('add-friend/<str:username>/', views.add_friend, name='add_friend'),
	path('remove-friend/<str:username>/', views.remove_friend, name='remove_friend'),
	path('profile/<str:username>/', views.user_profile, name='user_profile'),
	path('my_profile/', views.my_profile, name='my_profile'),
]