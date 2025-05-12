from django.shortcuts import render, redirect, get_object_or_404
from jeux_du_pong.models import Match
from django.contrib.auth.decorators import login_required
from .forms import UserProfileForm, UsernameProfileForm, AvatarProfileForm
from .models import CustomUser
from django.contrib import messages
from django.utils.translation import gettext as _
from django.views.decorators.csrf import csrf_exempt
from django.views.i18n import set_language as django_set_language
from django.conf import settings
from django.urls import reverse_lazy
from .jwt_auth import get_tokens_for_user, jwt_login_required
import json
from django.http import JsonResponse
from .validators import validate_not_banned_username, custom_username_validdators, validate_avatar
from django.core.exceptions import ValidationError
# Create your views here.

@login_required
def profile_update(request):
	# print("profile_update")
	if request.method == 'POST':
		username = request.POST.get('username')

		if username:
			try:
				# Check if username is not in banned list
				validate_not_banned_username(username)
				
				# Apply all custom validators
				for validator in custom_username_validdators:
					validator(username)
					
				if CustomUser.objects.filter(username=username).exists():
					messages.error(request, _("Username is already used."), extra_tags="error")
				else:
					request.user.username = username
					request.user.save()
					messages.success(request, _("Your username has been updated."), extra_tags="success")
			except ValidationError as e:
				messages.error(request, _(e.message), extra_tags="error")
		else:
			messages.error(request, _("Please enter a valid username."), extra_tags="error")
	return redirect('/users/my_profile/')



@login_required
def profile_avatar_update(request):
	# print("profile_update")
	if request.method == 'POST':
		avatar = request.FILES.get('avatar')
		if avatar:
			try:
				validate_avatar(avatar)
				request.user.avatar = avatar
				request.user.save()
				messages.success(request, _("Your avatar has been updated."), extra_tags="success")
			except ValidationError as e:
				messages.error(request, _(e.message), extra_tags="error")
		else:
			messages.error(request, _("Please enter a valid avatar."), extra_tags="error")
	return redirect('/users/my_profile/')



@login_required
def add_friend(request):
	username = request.GET.get('username')
	# print("request in add friend is : \n\t", request)#####
	if request.user.username == username:
		# messages.error(request, _("You can not be friends with yoursefl."), extra_tags="error")
		return (redirect('my_profile'))
	if request.user.friends.filter(username=username).exists():
		console.log("Already your bruv")
		# messages.error(request, _("You are already friends with %(username)s.") % {'username': username}, extra_tags="warning")
	else:
		user_to_add = get_object_or_404(CustomUser, username=username)
		request.user.friends.add(user_to_add)
		# print("username in add friend is : \n\t", username)####
		# messages.success(request, _("You are now friends with %(username)s.") % {'username': username}, extra_tags="success")
	return redirect(f'/api/users/profile/{username}')
	# print("\nuser_to_add in add friend is : \n\t", user_to_add.username, "\nrequest.user.username in add frisnd is : \n\t", request.user.username) #####
	# if user_to_add.username == request.user.username or request.user.friends.filter(username=user_to_add.username):
		# return redirect('my_profile')
	# request.user.friends.add(user_to_add)

@login_required
def remove_friend(request):
	username = request.GET.get('username')
	if request.user.username == username:
		# messages.error(request, _("As you can not be friends with yourself, you can not unfriend yourself."), extra_tags='error')
		return (redirect('my_profile'))
	if request.user.friends.filter(username=username).exists():
		user_to_remove = get_object_or_404(CustomUser, username=username)
		request.user.friends.remove(user_to_remove)
		# print("username in remove friend is : \n\t", username)####
		# messages.success(request, _("You removed %(username)s from your friends") % {'username': username}, extra_tags="success")
	else:
		console.log("Not your bruv")
		# messages.error(request, _("%(username)s is not in your friends list") % {'username': username}, extra_tags="warning")
	return redirect(f'/api/users/profile/{username}')

# @login_required
# def user_profile(request, username):
#	 print("request in user profil is : \n\t", request)#####
#	 profile_to_see = get_object_or_404(CustomUser,username=username)
#	 my_profile = request.user
#	 print("\nprofile to see in user_profile is : \n\t", profile_to_see.username, "\nrequest.user in add friend is : \n\t", request.user.username) #####
#	 if profile_to_see.username == my_profile.username:
#		 return render(request, 'users/profile.html', {'user': my_profile})
#	 else:
#		 return render(request, 'users/profile.html', {'user': profile_to_see})
#	 """ if username == request.user.username:
#		 user = get_object_or_404(CustomUser, username=request.user.username)
#	 else:
#		 user = get_object_or_404(CustomUser, username=username)
#	 return render(request, 'users/profile.html', {'user': request.user})
#	 return render(request, 'users/profile.html', {'user': user}) """

# from django_otp.decorators import otp_required
@login_required
# @otp_required
def user_profile(request, username):
	# print("username in user_profile is : \n\t", username, "\nrequest in user_profile is : \n\t", request, "\nrequest.user.username in user_profile is : \n\t", request.user.username) #####
	user = get_object_or_404(CustomUser, username=username)
	matches = Match.objects.filter(player=user) | Match.objects.filter(opponent_alias=user)
	isFriend = request.user.friends.filter(username=username).exists()
	# if user.username != request.user.username:
	return render(request, 'users/profil.html', {'user': user, 'matches': matches, 'isFriend': isFriend})
	# return render(request, 'users/profile.html', {'user': user})
	# else:
		# return render(request, 'users/profile.html', {'user': request.user})

@login_required
# @otp_required
def my_profile(request):
	matches = Match.objects.filter(player=request.user) | Match.objects.filter(opponent_alias=request.user)
	friends = request.user.friends.all()
	print("friends in my_profile is : \n\t", friends)#####
	form = UsernameProfileForm(instance=request.user)
	return(render(request, 'users/profil.html', {'user': request.user, 'matches': matches, 'friends': friends, 'form': form}))
	# return render(request, 'users/profile.html', {'user': request.user})

@login_required
def search_friends(request):
	# print("request in search friends is : \\n\\t", request)#####
	query = request.GET.get('q', '')
	print("query in search friends is : \\n\\t", query)#####
	user = request.user
	results_list = []
	if query:
		# results = CustomUser.objects.filter(username__icontains=query).exclude(id=user.id)
		# results = CustomUser.objects.filter(username__icontains=query)
		# Exclude the current user from search results
		results = CustomUser.objects.filter(username__icontains=query).exclude(id=user.id)
		results_list = [{'username': user.username, 'profile_url': f'/users/profile/{user.username}/'} for user in results]
	else:
		results = CustomUser.objects.none() # Return empty queryset if no query
	# print("query in search friends is : \\n\\t", query, "\\nresults in search friends is : \\n\\t", results)#####
	# return render(request, 'users/search_results.html', {'results': results, 'query': query})
	return JsonResponse({'results': results_list})

@jwt_login_required
def friends_list(request):
	friends = request.user.friends.all()
	return render(request, 'users/friends.html', {'friends': friends})



#override Setup view to save the user 2fa state (on or off)
from two_factor.views import SetupView
from django_otp import user_has_device

class CustomTwoFactorSetupView(SetupView):

	def done(self, form_list, **kwargs):
		print("======================== 2FA STATE ======================== \n")####

		response = super().done(form_list, **kwargs)
		user = self.request.user

		# Si l’utilisateur a activé 2FA, on le note en base
		if user_has_device(user):
			user.two_factor = True
			user.save(update_fields=['two_factor'])
		
		print("2FA STATE ======= ", user.two_factor)####

		return redirect('/api/users/accounts/two_factor/setup/complete/')
	

from django.views.generic import TemplateView
from django.urls import reverse_lazy

class CustomSetupCompleteView(TemplateView):
	template_name = 'two_factor/setup_complete.html'

	def get(self, request, *args, **kwargs):
		print("\n ~~~~~~~ 2FA STATE in SETUP COMPLETE ~~~~~~~ \n",)####
		# print("2FA STATE in SETUP COMPLETE ======= ", self.two_factor)
	#	 # tu peux set two_factor ici si ce n’est pas déjà fait
	#	 user = request.user
	#	 if not user.two_factor:
	#		 user.two_factor = True
	#		 user.save()

		# Rediriger directement sans afficher la page (optionnel)
		return redirect('/api/users/my_profile/')


# from two_factor.views import DisableView
# class CustomTwoFactorDisableView(DisableView):
# 	def done(self, form_list, **kwargs):
# 		print("======================== 2FA STATE in disable ======================== \n")

# 		response = super().done(form_list, **kwargs)
# 		user = self.request.user

# 		# Si l’utilisateur a désactivé 2FA, on le note en base
# 		if user_has_device(user):
# 			user.two_factor = True
# 			user.save(update_fields=['two_factor'])
		
# 		print("2FA STATE ======= ", user.two_factor)

# 		return redirect('two_factor_setup_complete')


from two_factor.views import DisableView
from django.shortcuts import redirect
from django.urls import reverse_lazy

class CustomDisable2FAView(DisableView):
	def post(self, request, *args, **kwargs):
		response = super().post(request, *args, **kwargs)
		print("======================== 2FA  in disable ======================== \n")####

		# Une fois la 2FA désactivée, on met le champ à False
		user = request.user
		if user.is_authenticated and user.two_factor:
			user.two_factor = False
			user.save()

		# return redirect(reverse_lazy('my_profile'))
		return redirect("/api/users/my_profile/")


# from django.contrib.auth.views import LoginView
# from two_factor.views import LoginView as TwoFactorLoginView
# from django.shortcuts import redirect
# from django.contrib.auth import authenticate, login
# from django.views import View
# from django.shortcuts import render

from allauth.account.views import LoginView as AllauthLoginView
# from django.shortcuts import redirect
from django.contrib.auth import login

class ConditionalLoginView(AllauthLoginView):
	def form_valid(self, form):
		user = form.user

		if user.two_factor:
			# Stocke l'utilisateur pour la suite du process 2FA
			print("/////////////////////// USER HAS ENABLED 2FA /////////////////////////")####
			self.request.session['pre_2fa_user_id'] = user.pk
			# return redirect('account_verify')
			return redirect('/api/users/accounts/two_factor/login/')
		else:
			print(self.request.session.get('pre_2fa_user_id'))
			login(self.request, user)
			
			# Generate JWT tokens for the user
			tokens = get_tokens_for_user(user)
			
			# Store tokens in session and cookies
			self.request.session["jwt_access_token"] = tokens['access']
			self.request.session["jwt_refresh_token"] = tokens['refresh']
			self.request.session.modified = True
			
			# Set JWT tokens as cookies to be picked up by JavaScript
			response = redirect(reverse_lazy('home'))
			response.set_cookie('jwt_access', tokens['access'], httponly=True, samesite='Lax', max_age=3600)  # 1 hour
			response.set_cookie('jwt_refresh', tokens['refresh'], httponly=True, samesite='Lax', max_age=86400)  # 1 day
			
			return response
	
	def form_invalid(self, form):
		"""
		Override form_invalid to handle login errors without trying to reverse 'account_signup'
		"""
		# Add error message using Django's messages framework
		from django.contrib import messages
		messages.error(self.request, _("Invalid username or password."), extra_tags='error')
		# Return to home page with form errors
		return redirect('home')


# from django.shortcuts import redirect
# from django.contrib.auth.views import LoginView
# from django_otp.forms import OTPAuthenticationForm

# class CustomTwoFactorLoginView(AllauthLoginView):
#     form_class = OTPAuthenticationForm

#     def form_valid(self, form):
#         user = form.user
        
#         if user.is_authenticated and user.two_factor:  # Si l'utilisateur a activé la 2FA
#             # Si l'utilisateur est authentifié, redirige directement vers la page TOTP
#             return redirect('account_verify')  # ou le nom de la vue de validation du code
#         else:
#             # Sinon, continue le processus de login traditionnel
#             return super().form_valid(form)

# class CustomTwoFactorLoginView(LoginView):
#     def dispatch(self, request, *args, **kwargs):
#         if request.user.is_authenticated:
#             if request.user.two_factor:
#                 return redirect('two_factor:verify')  # Skip la page login, va directement vers la validation du 2FA
#         return super().dispatch(request, *args, **kwargs)

@csrf_exempt
def set_language_and_remember(request):
	response = django_set_language(request)

	if hasattr(request, 'user') and request.user.is_authenticated:
		lang_code = request.POST.get('language')
		if lang_code in dict(settings.LANGUAGES):
			request.user.preferred_language = lang_code
			request.user.save()

	return response

from allauth.account.views import SignupView as AllauthSignupView
from django.contrib.auth import login

class CustomSignupView(AllauthSignupView):
	def form_valid(self, form):
		response = super().form_valid(form)
		user = self.user
		
		# Generate JWT tokens for the user
		tokens = get_tokens_for_user(user)
		
		# Store tokens in session and cookies
		self.request.session["jwt_access_token"] = tokens['access']
		self.request.session["jwt_refresh_token"] = tokens['refresh']
		self.request.session.modified = True
		
		# Set JWT tokens as cookies
		response.set_cookie('jwt_access', tokens['access'], httponly=True, samesite='Lax', max_age=3600)  # 1 hour
		response.set_cookie('jwt_refresh', tokens['refresh'], httponly=True, samesite='Lax', max_age=86400)  # 1 day
		
		return response
	
	def form_invalid(self, form):
		"""
		Override form_invalid to handle signup errors without trying to reverse 'account_login'
		"""
		# Add error messages using Django's messages framework
		for field, errors in form.errors.items():
			for error in errors:
				messages.error(self.request, f"{field}: {error}")
		
		# Return to home page with form errors
		return redirect('home')

from allauth.account.views import LogoutView as AllauthLogoutView

class CustomLogoutView(AllauthLogoutView):
    def dispatch(self, request, *args, **kwargs):
        # Call the parent class's dispatch method, which will handle the standard logout
        response = super().dispatch(request, *args, **kwargs)
        
        # Clear JWT cookies
        response.delete_cookie('jwt_access')
        response.delete_cookie('jwt_refresh')
        
        # Log the action for debugging
        print("======================== LOGOUT: JWT COOKIES CLEARED ========================")####
        
        return response

# Import the TwoFactorLoginView from django-two-factor-auth
from two_factor.views import LoginView as TwoFactorLoginView
from django.contrib.auth import get_user_model

class CustomTwoFactorLoginView(TwoFactorLoginView):
    """
    Custom two-factor authentication view that issues JWT tokens
    after successful 2FA verification.
    """
    
    def done(self, form_list, **kwargs):
        """
        Login the user and redirect to the home page after successful
        two-factor authentication.
        """
        # Call the parent method to handle the standard 2FA login
        response = super().done(form_list, **kwargs)
        
        # Generate JWT tokens for the authenticated user
        tokens = get_tokens_for_user(self.request.user)
        
        # Store tokens in session and cookies
        self.request.session["jwt_access_token"] = tokens['access']
        self.request.session["jwt_refresh_token"] = tokens['refresh']
        self.request.session.modified = True
        
        # Set JWT tokens as cookies to be picked up by JavaScript
        response.set_cookie('jwt_access', tokens['access'], httponly=True, samesite='Lax', max_age=3600)  # 1 hour
        response.set_cookie('jwt_refresh', tokens['refresh'], httponly=True, samesite='Lax', max_age=86400)  # 1 day
        
        print("======================== JWT TOKENS ISSUED AFTER 2FA ========================")
        
        return response
