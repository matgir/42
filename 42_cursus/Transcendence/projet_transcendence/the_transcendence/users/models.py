from django.contrib.auth.models import AbstractUser
from django.db import models

# Create your models here.

class CustomUser(AbstractUser):
	email =		models.EmailField(unique=True)
	username =	models.CharField(max_length=30, unique=True)
	# friends =	models.ManyToManyField("self")
	# add any additionnal fields here

	USERNAME_FIELD = 'username'
	REQUIRED_FIELDS = ['email']

	def __str__(self):
		return self.email