# from django.contrib.auth.models import AbstractUser
from django.db import models

# Create your models here.

class CustomUser(models.Model):
	username =	models.CharField(max_length=30, unique=True)
	is_connected = models.BooleanField(default=False)
	avatar = models.ImageField(upload_to="avatar/", default="default_avatar") #(default image if none provided)
	victory = PositiveIntegerField(default=0)
	defeat = PositiveIntegerField(default=0)
	# friends = ###
	# match_history = ### (1v1 games, dates, result of the game)
	# blocked_by_me = ###
	# blocked_by_them = ###

	# email =		models.EmailField(unique=True)
	# friends =	models.ManyToManyField("self")
	# add any additi  onnal fields here

	USERNAME_FIELD = 'username'
	REQUIRED_FIELDS = []

	def __str__(self):
		return self.username