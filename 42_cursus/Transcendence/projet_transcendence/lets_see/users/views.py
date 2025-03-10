from django.shortcuts import render, redirect, get_object_or_404
from django.contrib.auth.decorators import login_required
from .forms import UserProfileForm
from .models import CustomUser

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
    user_to_add = get_object_or_404(CustomUser, username=username)
    request.user.friends.add(user_to_add)
    return redirect('profile', username=username)