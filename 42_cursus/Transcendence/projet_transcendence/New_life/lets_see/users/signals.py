from django.db.models.signals import pre_save
from django.dispatch import receiver
from .models import CustomUser
from django.contrib.auth.signals import user_logged_in
from django.utils.translation import activate

@receiver(pre_save, sender=CustomUser)
def delete_old_avatar(sender, instance, **kwargs):
	try:
		old_avatar = sender.objects.get(pk=instance.pk).avatar
	except sender.DoesNotExist:
		return

	if old_avatar and old_avatar != instance.avatar and old_avatar.name != 'default.png':
		old_avatar.delete(save=False)

@receiver(user_logged_in)
def set_language_after_login(sender, request, user, **kwargs):
	if user.preferred_language:
		lang = user.preferred_language
		request.session['django_language'] = lang
		activate(lang)
		print(f"inside set_language_after_login\n language activated after login {lang}")

# @receiver(pre_save, sender=CustomUser)
# def assign_random_avatar(sender, instance, **kwargs):
# 	if not instance.pk and not instance.avatar: #only for new users without avatar
# 		defaults_dir = 'avatars/defaults/'
# 		available = ['default1.png', 'default2.png', 'default3.png', 'default4.png']
# 		instance.avatar = os.path.join(defaults_dir, random.choice(available))
