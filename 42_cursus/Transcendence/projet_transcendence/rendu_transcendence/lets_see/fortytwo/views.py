from django.shortcuts import render

# from django.shortcuts import render
from django.http import HttpResponse
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework.permissions import IsAuthenticated

# Create your views here.

################################################### PAGE DE REDIRECTION #############################
from django.shortcuts import redirect
from django.http import JsonResponse
import requests
import os
from django.urls import reverse
from django.conf import settings
from users.models import CustomUser
# from allauth.account.forms import LoginForm
from django.contrib.auth import login
from django.contrib.auth import get_backends
# from django.contrib.auth.decorators import login_required
from .forms import FortyTwoUsername

# @login_required
def fortytwo_username(request):
	print("forty_two_username")
	print("REQUEST de 42 >>> ", request)
	if request.method == 'POST':
		print("DANS IF >>>>>>>>>>>>>")
		form = FortyTwoUsername(request.POST, request.FILES, instance=request.user)
		if form.is_valid():
			form.save()
			# return
			return redirect('home')
			# return redirect('user_profile', username=request.user.username)
	else:
		print("DANS ELSE >>>>>>>>>>>>>")
		form = FortyTwoUsername(instance=request.user)
	return render(request, 'fortytwo/fortytwo_username.html', {'form': form})




# HELPFUL TOOL
# SUPPRIMER

def foo(ft):
    foo.counter += 1
    print ("Step %d -> " % foo.counter, ft, " function")
foo.counter = 0





print("\n\n===================== VIEW DJANGO PONG GAME ==========================\n\n")

# Récupérer le client_id et client_secret depuis les settings
CLIENT_ID = settings.OAUTH_CLIENT_ID
CLIENT_SECRET = settings.OAUTH_CLIENT_SECRET
# REDIRECT_URI = "http://localhost:8000/fortytwo/oauth_callback/"
REDIRECT_URI = settings.REDIRECT_URI
token_url = "https://api.intra.42.fr/oauth/token"

def oauth_callback(request):
    """Cette vue gère la redirection après l'authentification 42"""
    foo("oauth_callback")
    # Récupère le code d'autorisation depuis l'URL
    authorization_code = request.GET.get("code")
    # if not authorization_code:
    #     authorization_code = request.session["authorization_code"]

    print("code recu >>>>>>>>>>>>>>>>> ", authorization_code)
    
    if not authorization_code:
        return JsonResponse({"error": "1- Pas de code d'autorisation fourni"}, status=500)

    # Stocker le code en session avant la redirection
    request.session["authorization_code"] = authorization_code
    request.session.modified = True

    return (redirect("/fortytwo/"))




def exchange_code_for_token(request, code):
    foo( "exchange_code_for_token")
    print("dans exhange ft, code is : ", request.session.get("authorization_code"))
    data = {
        "grant_type": "authorization_code",
        "client_id": CLIENT_ID,
        "client_secret": CLIENT_SECRET,
        "code": code,
        "redirect_uri": REDIRECT_URI
    }
    # Envoie la requête à l'API de 42 pour obtenir le token
    response = requests.post(token_url, data=data)
    if response.status_code != 200:
        print("❌>> Erreur dans la requête :", response.status_code, response.text)
        return JsonResponse({"error": "Erreur lors de l'echange de code contre un token d'acces"}, status=500)
    access_token = response.json().get('access_token')
    if not access_token:
        return JsonResponse({"error": "2- Pas de code d'autorisation fourni"}, status=500)
    
    request.session["access_token"] = access_token
    print("1- DEBUG >>>", access_token)

    return (access_token)


################################################### PAGE DE REDIRECTION #############################

def get_42_user_info(access_token):
    headers = {
        "Authorization": f"Bearer {access_token}"
    }
    response = requests.get("https://api.intra.42.fr/v2/me", headers=headers)

    if response.status_code == 200:
        return response.json()  # Retourne les infos de l'utilisateur sous forme de dict
    else:
        return None


def is_token_valid(access_token):
    headers = {"Authorization": f"Bearer {access_token}"}
    response = requests.get("https://api.intra.42.fr/v2/me", headers=headers)
    return response.status_code == 200

def refresh_access_token(refresh_token):
    data = {
        "grant_type": "refresh_token",
        "client_id": CLIENT_ID,
        "client_secret": CLIENT_SECRET,
        "refresh_token": refresh_token
    }
    response = requests.post("https://api.intra.42.fr/oauth/token", data=data)

    if response.status_code == 200:
        return response.json().get("access_token")
    else:
        return None

from django.core.files.base import ContentFile #deplacer en haut du fichier
def download_avatar(url):
    response = requests.get(url)
    if response.status_code == 200:
        return ContentFile(response.content)
    return None

def	pong_game(request):
    foo("pong_game")
    authorization_code = request.session.get("authorization_code")
    if not authorization_code:
        return JsonResponse({"error": "Code d'autorisation manquant en session"}, status=500)
    print("Code récupéré dans pong_game >>>>>>>>>>>>>>>>>", authorization_code)

    # Maintenant, échange ce code contre un token
    access_token = request.session.get("access_token")
    if access_token:
        print ("Access token received!")
        return redirect('home')
        # return HttpResponse("Hello, this will be the pong game.")

    access_token = exchange_code_for_token(request, authorization_code)
    if not access_token:
        return JsonResponse({"error": "Erreur lors de l'echange du code contre token"}, status=500)
    
    if not is_token_valid(access_token):
        return JsonResponse({"error": "Token expired"}, status=401)


    user_info = get_42_user_info(access_token)
    if user_info:
        print("! Infos du user obtenues !")
        # print("Voici infos user >> ", user_info.get("login"))
        print("Voici infos user >> ", user_info)
    else:
        return JsonResponse({"error": "Impossible de récupérer les infos utilisateur"}, status=500)


        # Vérifier si l'utilisateur existe déjà
    user, created = CustomUser.objects.get_or_create(
        login_42=user_info["login"],
        # avatar=user_info["image"]["versions"]["small"],  # URL de l'avatar
        # avatar=download_avatar(user_info["image"]["versions"]["small"])
        defaults={
            "login_42": user_info["login"],  # Nom d'utilisateur 42
        }
    )


            # "avatar": user_info["image"]["link"]  # URL de l'avatar

    if created or not user.avatar or user.avatar.name == "default.png":
        avatar_file = download_avatar(user_info["image"]["versions"]["medium"])
        if avatar_file:
            user.avatar.save(f"{user_info['login']}_avatar.jpg", avatar_file)
            user.save()

    ### test mateo
    # user.username = user.login_42
    # print("DEBUG : USERNAME=LOGIN42? --> ", user.username, "=", user.login_42)
    ### test mateo

            ###### REACTIVER ######
    # Mettre à jour les infos si l'utilisateur existe déjà
    # if not created:
    #     user.username = user_info["login"]
    #     user.avatar = user_info["image"]["versions"]["small"]
    #     # avatar=download_avatar(user_info["image"]["versions"]["small"])
    #     print(user.avatar)
    #     user.save()

    print("REQUEST >>> ", request)
    print(request, request.method, request.POST, request.FILES, request.user)

    print("42 USER >>> ", user)
    # Connecter l'utilisateur automatiquement

    # Assigner un backend d'authentification au user
    user.backend = 'allauth.account.auth_backends.AuthenticationBackend'
    # fortytwo_username(request, user)
    login(request, user)
    print(request.user)###


    request.session["access_token"] = access_token
    request.session.modified = True
    print("2- ACCESS TOKEN >>>", request.session.get("access_token"))

    # return (fortytwo_username(request))
    if (user.username):
        return (redirect("home"))
    return (redirect("/fortytwo/fortytwo_username/"))
    # return (redirect("home"))
    # return (HttpResponse("Hello, this will be the pong game."))

class ProtectedView(APIView):
	permission_classes = [IsAuthenticated]

	def get(self, request):
		return Response({"message": "This view is protected"})
    



    
    



