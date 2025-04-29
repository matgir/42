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
from django.views.i18n import JavaScriptCatalog
from django.conf.urls.i18n import i18n_patterns
from users.views import set_language_and_remember
from django.conf import settings #####
from django.conf.urls.static import static #####

urlpatterns = [
    path('i18n/setlang/', set_language_and_remember, name='set_language'),
    path('jsi18n/', JavaScriptCatalog.as_view(), name='javascript-catalog'),
    path('i18n/', include('django.conf.urls.i18n')),
]

urlpatterns += i18n_patterns(
    # path('', include('lets_see.urls')),
    path('', TemplateView.as_view(template_name='home.html'), name='home'),
    path('admin/', admin.site.urls),
    path('users/', include('users.urls')),
    path('jeux_du_pong/', include('jeux_du_pong.urls')),
    path('tournament/', include('tournament.urls')),
    path('fortytwo/', include('fortytwo.urls')),
)

if settings.DEBUG:#####
    urlpatterns += static(settings.MEDIA_URL, document_root=settings.MEDIA_ROOT)#####
