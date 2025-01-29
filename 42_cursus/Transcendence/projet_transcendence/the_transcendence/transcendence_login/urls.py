from django.urls import path
from . import views

urlpatterns = [
	path("", views.transcendence_login, name="transcendence_login"),
]