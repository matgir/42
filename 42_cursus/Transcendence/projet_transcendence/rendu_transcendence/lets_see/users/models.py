from django.contrib.auth.models import AbstractUser
from django.db import models
from .validators import validate_avatar

# Create your models here.

class CustomUser(AbstractUser):
	username = models.CharField(max_length=30, unique=True)
	avatar = models.ImageField(
		upload_to="avatars/",
		validators=[validate_avatar],
		default="default.png"
	)
	friends = models.ManyToManyField('self', symmetrical=False, blank=True)
	wins = models.PositiveIntegerField(default=0)
	losses = models.PositiveIntegerField(default=0)
	online_status = models.BooleanField(default=False)

	def __str__(self):
		return self.username