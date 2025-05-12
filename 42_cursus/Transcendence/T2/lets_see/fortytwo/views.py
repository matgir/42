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
from django.utils.translation import gettext as _
from users.jwt_auth import get_tokens_for_user  # Import the JWT token function
from users.validators import validate_not_banned_username, custom_username_validdators, validate_min_username_length
from django.contrib import messages
from django.core.exceptions import ValidationError

# @login_required
def fortytwo_username(request):
	# Get user from session
	user_id = request.session.get("user_to_connect_id")
	if not user_id:
		# Handle case when no user_id is in session
		return redirect('home')
		
	try:
		user = CustomUser.objects.get(id=user_id)
		validate_not_banned_username(user.login_42)
		for validator in custom_username_validdators:
			validator(user.login_42)
		if CustomUser.objects.filter(username=user.login_42).exists():
			user.username = user.login_42 + user_id
		else:
			user.username = user.login_42
		user.save()
	except CustomUser.DoesNotExist:
		return redirect('home')
	

	user.backend = 'allauth.account.auth_backends.AuthenticationBackend'


	if request.method == 'POST':
		form = FortyTwoUsername(request.POST, request.FILES, instance=user)
		if form.is_valid():
			login(request, user)
			form.save()
			# Generate JWT tokens for the user
			tokens = get_tokens_for_user(request.user)
			
			# Store tokens in session and cookies
			request.session["jwt_access_token"] = tokens['access']
			request.session["jwt_refresh_token"] = tokens['refresh']
			request.session.modified = True
			
			# Set JWT tokens as cookies to be picked up by JavaScript
			response = redirect('home')
			response.set_cookie('jwt_access', tokens['access'], httponly=True, samesite='Lax', max_age=3600)  # 1 hour
			response.set_cookie('jwt_refresh', tokens['refresh'], httponly=True, samesite='Lax', max_age=86400)  # 1 day
			
			return response
	else:
		form = FortyTwoUsername(instance=user)
	
	return render(request, 'fortytwo/fortytwo_username.html', {'form': form})




# HELPFUL TOOL
# SUPPRIMER

# def foo(ft):
#	foo.counter += 1
#	 print ("Step %d -> " % foo.counter, ft, " function")
# foo.counter = 0





# print("\n\n===================== VIEW DJANGO PONG GAME ==========================\n\n")

# Récupérer le client_id et client_secret depuis les settings
CLIENT_ID = settings.OAUTH_CLIENT_ID
CLIENT_SECRET = settings.OAUTH_CLIENT_SECRET
# REDIRECT_URI = "http://localhost:8000/fortytwo/oauth_callback/"
REDIRECT_URI = settings.REDIRECT_URI
token_url = "https://api.intra.42.fr/oauth/token"

def oauth_callback(request):
	"""Cette vue gère la redirection après l'authentification 42"""
	# foo("oauth_callback")
	# Récupère le code d'autorisation depuis l'URL
	authorization_code = request.GET.get("code")
	# if not authorization_code:
	#	 authorization_code = request.session["authorization_code"]

	# print("code recu >>>>>>>>>>>>>>>>> ", authorization_code)
		
	if not authorization_code:
		return JsonResponse({"error": _("1- No authorization code given")}, status=500)
		# return JsonResponse({"error": "1- Pas de code d'autorisation fourni"}, status=500)

	# Stocker le code en session avant la redirection
	request.session["authorization_code"] = authorization_code
	request.session.modified = True

	return (redirect("/fortytwo/"))




def exchange_code_for_token(request, code):
	# foo( "exchange_code_for_token")
	# print("dans exhange ft, code is : ", request.session.get("authorization_code"))
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
		# print("❌>> Erreur dans la requête :", response.status_code, response.text)
		return JsonResponse({"error": _("Error during the access token exchange")}, status=500)
		# return JsonResponse({"error": "Erreur lors de l'echange de code contre un token d'acces"}, status=500)
	access_token = response.json().get('access_token')
	if not access_token:
		return JsonResponse({"error": _("2- No authorization code given")}, status=500)
		# return JsonResponse({"error": "2- Pas de code d'autorisation fourni"}, status=500)
		
	request.session["access_token"] = access_token
	# print("1- DEBUG >>>", access_token)

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
	# foo("pong_game")
	authorization_code = request.session.get("authorization_code")
	if not authorization_code:
		return JsonResponse({"error": _("Missing authorization code during session")}, status=500)
		# return JsonResponse({"error": "Code d'autorisation manquant en session"}, status=500)
	# print("Code récupéré dans pong_game >>>>>>>>>>>>>>>>>", authorization_code)

	# Maintenant, échange ce code contre un token
	access_token = request.session.get("access_token")
	if access_token:
		# print ("Access token received!")
		return redirect('home')
		# return HttpResponse("Hello, this will be the pong game.")

	access_token = exchange_code_for_token(request, authorization_code)
	if not access_token:
		return JsonResponse({"error": _("Error during the exchange of the code for the token")}, status=500)
		# return JsonResponse({"error": "Erreur lors de l'echange du code contre token"}, status=500)
		
	if not is_token_valid(access_token):
		return JsonResponse({"error": _("Token expired")}, status=401)


	user_info = get_42_user_info(access_token)
	if user_info:
		print("! Infos du user obtenues !")####
		# print("Voici infos user >> ", user_info.get("login"))
		# print("Voici infos user >> ", user_info)
	else:
		return JsonResponse({"error": _("Could not collect user informations")}, status=500)
		# return JsonResponse({"error": "Impossible de récupérer les infos utilisateur"}, status=500)


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

	try:
		if not user.username:
			validate_not_banned_username(user.login_42)
			validate_min_username_length(user.login_42)
			for validator in custom_username_validdators:
				validator(user.login_42)
			if CustomUser.objects.filter(username=user.login_42).exists():
				messages.error(request, _("Username already taken. updated to: ") + user.login_42 + str(user.id), extra_tags="warning")
				user.username = user.login_42 + str(user.id)
			else:
				messages.error(request, _("Your username is: ") + user.login_42, extra_tags="warning")
				user.username = user.login_42
			user.save()
	except ValidationError as e:
		messages.error(request, _(e.message), extra_tags="warning")
		return redirect('home')

	request.session["access_token"] = access_token
	# request.session["user_to_connect_id"] = user.id
	request.session.modified = True
	# user.backend = 'allauth.account.auth_backends.AuthenticationBackend'
		
	# Generate JWT tokens for the user if they already have a username
	if user.username:
		user.backend = 'allauth.account.auth_backends.AuthenticationBackend'
		login(request, user)
		tokens = get_tokens_for_user(user)
		
		request.session["jwt_access_token"] = tokens['access']
		request.session["jwt_refresh_token"] = tokens['refresh']
		request.session.modified = True
		
		response = redirect("home")
		response.set_cookie('jwt_access', tokens['access'], httponly=True, samesite='Lax', max_age=3600)  # 1 hour
		response.set_cookie('jwt_refresh', tokens['refresh'], httponly=True, samesite='Lax', max_age=86400)  # 1 day
		
		return response
	else:
		return redirect("home")
		
	# If user doesn't have a username yet, redirect to the username setting page
	# JWT tokens will be generated after they set their username in fortytwo_username view
	# return redirect("/fortytwo/fortytwo_username/")
	# return (redirect("home"))
	# return (HttpResponse("Hello, this will be the pong game."))

# class ProtectedView(APIView):
# 	permission_classes = [IsAuthenticated]

# 	def get(self, request):
# 		return Response({"message": "This view is protected"})