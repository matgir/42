from django.urls import path
from . import views

app_name = "pong_game"
urlpatterns = [
	path("", views.pong_game, name="pong game"),
]