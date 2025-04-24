from django.shortcuts import render
from django.contrib.auth.decorators import login_required

@login_required
def pong_game(request):
	return render(request, 'jeux_du_pong/game.html', {'player_name': request.user.username})