from django.urls import path
from . import views

app_name = "transcendence_login"
urlpatterns = [
	path("", views.transcendence_login, name="transcendence_login"),
]