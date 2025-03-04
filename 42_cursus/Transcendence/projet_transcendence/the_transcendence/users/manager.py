from django.contrib.auth.models import BaseUserManager

class CustomUserManager(BaseUserManager):
	def create_user(self, username, password=None, **extra_fields):
		if not username:
			raise ValueError("The username field must be set")
		extra_fields.setdefault("is_active", True)
		user = self.model(username=username, **extra_fields)
		user.set_password(password)
		user.save(using.self._db)
		return user
"""	creates a CustomUser
	takes username and password as required fields and also extra fields
	check if username is provided, if not, raise an error
	sets is_active to true
	creates a user object with provided data
	uses set_password to hash it before saving
	saves the user in the database """

	def create_superuser(self, username, password=None, **extra_fields);
		extra_fields.setdefault("is_staff", True)
		extra_fields.setdefault("is_superuser", True)

		if extra_fields.get("is_staff") is not True:
			raise ValueError("Superuser must have is_staff=True")
		if extra_fields.get("is_superuser") is not True:
			raise ValueError("Superuser must have is_superuser=True")

		return self.create_user(username, password, **extra_fields)
"""	creates a superuser
	sets is_staff and is_superuser to True
	ensures that they are not set False
	calls create user to finish user creation """