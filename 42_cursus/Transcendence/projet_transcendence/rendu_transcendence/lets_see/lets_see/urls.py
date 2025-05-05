from django.contrib import admin
from django.urls import path, include, re_path
from django.views.generic import TemplateView
from django.views.i18n import JavaScriptCatalog
from django.conf.urls.i18n import i18n_patterns
from users.views import set_language_and_remember
from django.conf import settings #####
from django.conf.urls.static import static #####
from users import views as users_views
from . import views
from two_factor.urls import urlpatterns as tf_urls

# API endpoints for router.js to fetch content
api_urlpatterns = [
    # SPA route endpoints that serve content for router.js
    path('home/', TemplateView.as_view(template_name='home.html'), name='home_content'),
    path('go_to_signup_page/', TemplateView.as_view(template_name='signup.html'), name='go_to_signup_page'),
    # path('go_to_signin_page/', TemplateView.as_view(template_name='home.html'), name='go_to_signin_page'),

    # path('signup_submit/', TemplateView.as_view(template_name='????.html'), name='signup_submit'),
    # path('signin_submit/', TemplateView.as_view(template_name='????.html'), name='signin_submit'),
    
    path('vs_tournois/', TemplateView.as_view(template_name='vs_tournois.html'), name='vs_tournois'), 
    path('pong/', TemplateView.as_view(template_name='pong.html'), name='pong'), 
    path('choose_your_perso/', TemplateView.as_view(template_name='choose_your_perso.html'), name='choose_your_perso'), 
    path('tournois/', TemplateView.as_view(template_name='tournois.html'), name='tournois'),
    path('duel/', TemplateView.as_view(template_name='duel.html'), name='duel'),
    path('basic_setting/', TemplateView.as_view(template_name='basic_setting.html'), name='basic_setting'), 
    path('basic_setting_duel/', TemplateView.as_view(template_name='basic_setting_duel.html'), name='basic_setting_duel'), 

    path('profil/', users_views.my_profile, name='my_profil'),
    # path('profil/', TemplateView.as_view(template_name='profil.html'), name='profil'),  
    # path('avatar/', TemplateView.as_view(template_name='avatar.html'), name='avatar'), 
    path('avatar/', TemplateView.as_view(template_name='avatar.html'), name='avatar'), 
    
    path('testeur/', TemplateView.as_view(template_name='testeur.html'), name='testeur'), 
    path('1_space_cubes/', TemplateView.as_view(template_name='1_space_cubes.html'), name='1_space_cubes'), 
    path('2_pink_cubes/', TemplateView.as_view(template_name='2_pink_cubes.html'), name='2_pink_cubes'), 
    path('3_blue_rubix/', TemplateView.as_view(template_name='3_blue_rubix.html'), name='3_blue_rubix'), 
    path('4_fall/', TemplateView.as_view(template_name='4_fall.html'), name='4_fall'), 
    path('6_torus/', TemplateView.as_view(template_name='6_torus.html'), name='6_torus'), 
    # path('profil/avatar/', TemplateView.as_view(template_name='avatar.html'), name='avatar'), 
    path('users/', include('users.urls')),
    path('tournament/', include('tournament.urls')),
    path('fortytwo/', include('fortytwo.urls')),
    path('404/', TemplateView.as_view(template_name='404.html'), name='404'),
]


urlpatterns = [
    path('setlang/', set_language_and_remember, name='set_language'),
    path('jsi18n/', JavaScriptCatalog.as_view(), name='javascript-catalog'),
    # path('admin/', admin.site.urls),    
    # Serve API endpoints for AJAX content loading
    path('api/', include((api_urlpatterns, 'api'))),
    
    
    # Include other app URLs
    path('jeux_du_pong/', include('jeux_du_pong.urls')),
    # path('users/', include('users.urls')),
    path('', include(tf_urls)),

    # Base SPA container - this should be the entry point
    path('', views.home_view, name='home'),
    # Catch-all pattern for SPA routes - serve the base.html for client-side routing
    # This should be the last URL pattern to avoid overriding more specific ones
    re_path(r'^(?!admin/|api/|static/|media/).*$', 
            views.base_view, name='spa_routes'),
]

if settings.DEBUG:
    urlpatterns += static(settings.MEDIA_URL, document_root=settings.MEDIA_ROOT)
