from django.contrib.auth.models import AbstractUser
from django.db import models
from .validators import validate_avatar
import uuid
import os
from PIL import Image
from django.conf import settings

# modify the name of the uploaded avatar so that if 2 user upload
# an avatar with the same name django does not mix them
def avatar_upload_path(instance, filename):
	ext = filename.split('.')[-1] # get file extension
	filename = f"{uuid.uuid4()}.{ext}" # generate unique filename
	return os.path.join('avatars', filename) # saves in media avatars

class CustomUser(AbstractUser):
	username = models.CharField(max_length=30, unique=True)
	avatar = models.ImageField(
		upload_to=avatar_upload_path,
		validators=[validate_avatar],
		default="default.png"
	)
	friends = models.ManyToManyField('self', symmetrical=False, blank=True)
	wins = models.PositiveIntegerField(default=0)
	losses = models.PositiveIntegerField(default=0)
	online_status = models.BooleanField(default=False)
	login_42 = models.CharField(max_length=30, blank=True)

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