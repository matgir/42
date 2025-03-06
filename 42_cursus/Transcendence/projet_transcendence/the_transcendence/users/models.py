from django.contrib.auth.models import AbstractUser
from django.db import models
from users.manager import CustomUserManager
from django.contrib.auth.models import PermissionsMixin

# Create your models here.

class CustomUser(AbstractUser, PermissionsMixin):
	username =	models.CharField(max_length=30, unique=True)
	is_connected = models.BooleanField(default=False)
	avatar = models.ImageField(upload_to="avatar/", default="default_avatar") #(default image if none provided)
	victory = models.PositiveIntegerField(default=0)
	defeat = models.PositiveIntegerField(default=0)
	# is_active = models.BooleanField(default=True)
	# is_staff = models.BooleanField(default=False)
	# is_superuser = models.BooleanField(default=False)
	# friends = ###
	# match_history = ### (1v1 games, dates, result of the game)
	# blocked_by_me = ###
	# blocked_by_them = ###

	# email =		models.EmailField(unique=True)
	# friends =	models.ManyToManyField("self")
	# add any additi  onnal fields here

	objects = CustomUserManager()

	USERNAME_FIELD = 'username'
	REQUIRED_FIELDS = []

	def __str__(self):
		return self.username