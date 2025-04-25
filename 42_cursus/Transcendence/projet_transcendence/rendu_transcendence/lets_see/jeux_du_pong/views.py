from django.shortcuts import render
from django.contrib.auth.decorators import login_required
from django.views.decorators.csrf import csrf_exempt
from django.http import JsonResponse
import json
from .models import Match

@login_required
def pong_game(request):
	return render(request, 'jeux_du_pong/game.html', {'player_name': request.user.username})

@csrf_exempt
@login_required
def report_match(request):
	if request.method == "POST":
		data = json.loads(request.body)

		result = data.get("result")
		player_score = data.get("player_score")
		opponent_score = data.get("opponent_score")
		opponent_alias = data.get("opponent_alias", "Player 2")

		Match.objects.create(
			player=request.user,
			opponent_alias=opponent_alias,
			result=result,
			player_score=player_score,
			opponent_score=opponent_score
		)

		if result == "win":
			request.user.wins += 1
		elif result == "loss":
			request.user.losses += 1
		request.user.save()

		return JsonResponse({"status": "ok"})
	return JsonResponse({"error": "Invalid request"}, status=400)