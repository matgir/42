from django.urls import path
from . import views

# app_name = "tournament"

urlpatterns = [
	path('<str:username>/match_history/', views.match_history, name='match_history'),
	path('my_match_history/', views.my_match_history, name='my_match_history'),
]