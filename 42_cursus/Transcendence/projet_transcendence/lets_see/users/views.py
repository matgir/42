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
    return redirect('user_profile', username=username)

@login_required
def user_profile(request, username):
    user = get_object_or_404(CustomUser, username=username)
    return render(request, 'users/profile.html', {'user': user})

@login_required
def search_friends(request):
    query = request.GET.get('q', '')
    results = CustomUser.objects.filter(username__icontains=query) if query else None
    return render(request, 'users/search_results.html', {'results': results, 'query': query})