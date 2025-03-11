from django.shortcuts import render
from .models import Match
from users.models import CustomUser
from django.contrib.auth.decorators import login_required

# Create your views here.

@login_required
def match_history(request, username):
	user = CustomUser.objects.get(username=username)
	matches = Match.objects.filter(player1=user) | Match.objects.filter(player2=user)
	return render(request, 'tournament/match_history.html', {'matches':matches, 'user':user})