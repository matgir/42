from django.contrib.auth.models import AbstractUser
from django.db import models

# Create your models here.

class CustomUser(AbstractUser):
	display_name = models.CharField(max_length=30, unique=True)
	avatar = models.ImageField(upload_to='users_avatars/', default='default_avatar.png')
	friends = models.ManyToManyField('self', blank=True)
	wins = models.PositiveIntegerField(default=0)
	losses = models.PositiveIntegerField(default=0)
	online_status = models.BooleanField(default=False)

	def __str__(self):
		return self.display_name