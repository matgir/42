from django.urls import path
from .views import pong_game

urlpatterns = [
	path('pong/', pong_game, name='pong_game'),
]