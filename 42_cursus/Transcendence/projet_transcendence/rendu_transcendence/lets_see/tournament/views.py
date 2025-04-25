from django.shortcuts import render, get_object_or_404
from jeux_du_pong.models import Match
from users.models import CustomUser
from django.contrib.auth.decorators import login_required

# Create your views here.

@login_required
def match_history(request, username):
	user = get_object_or_404(CustomUser, username=username)
	matches = Match.objects.filter(player=user).order_by('-played_at')
	return render(request, 'tournament/match_history.html', {
		'matches': matches,
		'user_profile': user,
	})

@login_required
def my_match_history(request):
	return match_history(request, request.user.username)
	# user = CustomUser.objects.get(username=username)
	# matches = Match.objects.filter(player1=user) | Match.objects.filter(player2=user)
	# return render(request, 'tournament/match_history.html', {'matches':matches, 'user':user})