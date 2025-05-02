from django.urls import path
from . import views

app_name = "fortytwo"
urlpatterns = [
	path("oauth_callback/", views.oauth_callback, name="oauth_callback"),
	path("", views.pong_game, name="pong_game"),
	path("fortytwo_username/", views.fortytwo_username, name="fortytwo_username"),
]



