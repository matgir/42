from django.db import models
from users.models import CustomUser

# Create your models here.

class Match(models.Model):
	player1 = models.ForeignKey(CustomUser, related_name='match_as_player1', on_delete=models.CASCADE)
	player2 = models.ForeignKey(CustomUser, related_name='match_as_player2', on_delete=models.CASCADE)
	winner = models.ForeignKey(CustomUser, related_name='matches_won', on_delete=models.CASCADE, null=True, blank=True)
	date_played = models.DateTimeField(auto_now_add=True)

	def __str__(self):
		return f"{self.player1} vs {self.player2}"