from django.urls import path
from . import views

urlpatterns = [
	path("", views.pong_game, name="pong game"),
]