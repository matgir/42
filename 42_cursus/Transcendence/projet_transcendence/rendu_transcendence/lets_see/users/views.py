from django.shortcuts import render, redirect, get_object_or_404
from django.contrib.auth.decorators import login_required
from .forms import UserProfileForm
from .models import CustomUser
from django.contrib import messages

# Create your views here.

@login_required
def profile_update(request):
	if request.method == 'POST':
		form = UserProfileForm(request.POST, request.FILES, instance=request.user)
		if form.is_valid():
			form.save()
			return redirect('profile', username=request.user.username)
	else:
		form = UserProfileForm(instance=request.user)
	return render(request, 'users/profile_update.html', {'form': form})

@login_required
def add_friend(request, username):
	# print("request in add friend is : \n\t", request)#####
	if request.user.username == username:
		messages.error(request, "You can not be friends with yoursefl.", extra_tags="error")
		return (my_profile(request))
	if request.user.friends.filter(username=username).exists():
		messages.error(request, f"You are already friends with {username}.", extra_tags="warning")
	else:
		user_to_add = get_object_or_404(CustomUser, username=username)
		request.user.friends.add(user_to_add)
		messages.success(request, f"You are now friends with {username}.", extra_tags="success")
	return redirect('user_profile', username=username)
	# print("\nuser_to_add in add friend is : \n\t", user_to_add.username, "\nrequest.user.username in add frisnd is : \n\t", request.user.username) #####
	# if user_to_add.username == request.user.username or request.user.friends.filter(username=user_to_add.username):
		# return redirect('my_profile')
	# request.user.friends.add(user_to_add)

@login_required
def remove_friend(request, username):
	if request.user.friends.filter(username=username).exists():
		user_to_remove = get_object_or_404(CustomUser, username=username)
		request.user.friends.remove(user_to_remove)
		messages.success(request, f"You removed {username} from your friends", extra_tags="success")
	else:
		messages.error(request, f"{username} is not in your friends list", extra_tags="warning")
	return redirect('user_profile', username=username)

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

@login_required
def user_profile(request, username):
	# print("username in user_profile is : \n\t", username, "\nrequest in user_profile is : \n\t", request, "\nrequest.user.username in user_profile is : \n\t", request.user.username) #####
	user = get_object_or_404(CustomUser, username=username)
	# if user.username != request.user.username:
	return render(request, 'users/profile.html', {'user': user})
	# else:
		# return render(request, 'users/profile.html', {'user': request.user})

@login_required
def my_profile(request):
	return(user_profile(request, request.user.username))
	# return render(request, 'users/profile.html', {'user': request.user})

@login_required
def search_friends(request):
	# print("request in search friends is : \n\t", request)#####
	query = request.GET.get('q', '')
	user = request.user
	if query:
		results = CustomUser.objects.filter(username__icontains=query).exclude(id=user.id)
	else:
		None
	# print("query in search friends is : \n\t", query, "\nresults in search friends is : \n\t", results)#####
	return render(request, 'users/search_results.html', {'results': results, 'query': query})