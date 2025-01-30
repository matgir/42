"""
URL configuration for global_transcendence project.

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/5.1/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path, include
from users.views import CustomTokenObtainPairView, CustomTokenRefreshView, RegisterView
from pong_game.views import ProtectedView

urlpatterns = [
    path('where_you_deal_with_things/', admin.site.urls),
    # this is the admin url, changed to not have the generic name
    path('transcendence_login/', include("transcendence_login.urls")),
    path("pong_game/", include("pong_game.urls")),
    path('api/token/', CustomTokenObtainPairView.as_view(), name='token_obtain_pair'),
    path('api/token/refresh/', CustomTokenRefreshView.as_view(), name='token_refresh'),
    path('api/register/', RegisterView.as_view(), name='register'),
    path('api/protected/', ProtectedView.as_view(), name='protected'),
]
