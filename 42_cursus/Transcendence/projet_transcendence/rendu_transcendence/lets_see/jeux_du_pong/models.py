from django.db import models
from django.conf import settings

class Match(models.Model):
	player = models.ForeignKey(settings.AUTH_USER_MODEL, on_delete=models.CASCADE, related_name='matches')
	opponent_alias = models.CharField(max_length=50)
	result = models.CharField(max_length=10, choices=[('win', 'Win'), ('loss', 'Loss')])
	player_score = models.PositiveIntegerField()
	opponent_score = models.PositiveIntegerField()
	played_at = models.DateTimeField(auto_now_add=True)

	def __str__(self):
		return f"{self.player.username} vs {self_opponent_alias} - {self.result}"