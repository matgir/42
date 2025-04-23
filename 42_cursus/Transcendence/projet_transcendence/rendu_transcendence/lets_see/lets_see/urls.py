"""
URL configuration for lets_see project.

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
from django.views.generic import TemplateView
from django.conf import settings #####
from django.conf.urls.static import static #####
import users

urlpatterns = [
    path('admin/', admin.site.urls),
    path('users/', include('users.urls')),
    path('', TemplateView.as_view(template_name='home.html'), name='home'),

    path('go_to_signup_page/', TemplateView.as_view(template_name='signup.html'), name='go_to_signup_page'),
    # path('go_to_signin_page/', TemplateView.as_view(template_name='home.html'), name='go_to_signin_page'),

    path('signup_submit/', TemplateView.as_view(template_name='????.html'), name='signup_submit'),
    path('signin_submit/', TemplateView.as_view(template_name='????.html'), name='signin_submit'),
    
    path('game_home/', TemplateView.as_view(template_name='game_home.html'), name='game_home'), 
    path('pong/', TemplateView.as_view(template_name='pong.html'), name='pong'), 
    # path('profil/', users.views.my_profile, name='my_profil'),
    # path('profil/', TemplateView.as_view(template_name='profil.html'), name='profil'),  
    # path('avatar/', TemplateView.as_view(template_name='avatar.html'), name='avatar'), 
    path('avatar/', TemplateView.as_view(template_name='avatar.html'), name='avatar'), 
    
    path('testeur/', TemplateView.as_view(template_name='testeur.html'), name='testeur'), 
    path('1_space_cubes/', TemplateView.as_view(template_name='1_space_cubes.html'), name='1_space_cubes'), 
    path('2_pink_cubes/', TemplateView.as_view(template_name='2_pink_cubes.html'), name='2_pink_cubes'), 
    path('3_blue_rubix/', TemplateView.as_view(template_name='3_blue_rubix.html'), name='3_blue_rubix'), 
    path('4_fall/', TemplateView.as_view(template_name='4_fall.html'), name='4_fall'), 
    path('5_torus_knot/', TemplateView.as_view(template_name='5_torus_knot.html'), name='5_torus_knot'), 
    path('6_torus/', TemplateView.as_view(template_name='6_torus.html'), name='6_torus'), 

    # path('profil/avatar/', TemplateView.as_view(template_name='avatar.html'), name='avatar'), 
    path('tournament/', include('tournament.urls')),
    path('fortytwo/', include('fortytwo.urls')),
]

if settings.DEBUG:#####
    urlpatterns += static(settings.MEDIA_URL, document_root=settings.MEDIA_ROOT)#####
