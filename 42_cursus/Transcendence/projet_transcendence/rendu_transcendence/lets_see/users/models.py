from django.contrib.auth.models import AbstractUser
from django.db import models
from .validators import validate_avatar, validate_not_banned_username
import uuid
import os
from PIL import Image
from django.conf import settings
from django.utils.translation import gettext_lazy as _

LANGUAGE_CHOICES = settings.LANGUAGES

# modify the name of the uploaded avatar so that if 2 user upload
# an avatar with the same name django does not mix them
def avatar_upload_path(instance, filename):
	ext = filename.split('.')[-1] # get file extension
	filename = f"{uuid.uuid4()}.{ext}" # generate unique filename
	return os.path.join('avatars', filename) # saves in media avatars

class CustomUser(AbstractUser):
	two_factor = models.BooleanField(default=False)
	username = models.CharField(
		max_length=30,
		unique=True,
		validators=[validate_not_banned_username]
	)
	avatar = models.ImageField(
		upload_to=avatar_upload_path,
		validators=[validate_avatar],
		default="default.png"
	)
	friends = models.ManyToManyField('self', symmetrical=False, blank=True)
	wins = models.PositiveIntegerField(default=0)
	losses = models.PositiveIntegerField(default=0)
	online_status = models.BooleanField(default=False)
	login_42 = models.CharField(max_length=30, null=False)
	preferred_language = models.CharField(
		max_length=10,
		choices=LANGUAGE_CHOICES,
		default='en',
		verbose_name=_("Prefered Language")
	)

	def __str__(self):
		return self.username

	def save(self, *args, **kwargs):
		super().save(*args, **kwargs)

		if self.avatar:
			avatar_path = self.avatar.path
			try:
				img = Image.open(avatar_path)
				img = img.convert('RGB') # convert to RGB in case of PNG with alpha
				img = img.resize((256, 256), Image.LANCZOS)
				img.save(avatar_path, format='JPEG', quality=90)
			except Exception as e:
				print(f"[Avatar resize error] {e}")