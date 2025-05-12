from django.urls import path
from . import views

# app_name = "tournament"

urlpatterns = [
	path('<str:username>/history/', views.match_history, name='match_history'),
]