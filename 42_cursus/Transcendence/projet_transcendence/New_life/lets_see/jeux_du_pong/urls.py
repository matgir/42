from django.urls import path
from .views import pong_game, report_match

urlpatterns = [
	path('pong/', pong_game, name='pong_game'),
	path('report-match/', report_match, name='report_match'),
]