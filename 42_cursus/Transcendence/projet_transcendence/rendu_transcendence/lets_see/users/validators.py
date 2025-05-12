from django.contrib.auth.validators import ASCIIUsernameValidator
from django.core.exceptions import ValidationError
from django.template.defaultfilters import filesizeformat
from PIL import Image
from django.utils.translation import gettext as _
# from .banned_usernames 
custom_username_validdators = [ASCIIUsernameValidator()]
BANNED_USERNAMES = [
	"admin", "administrator", "root", "support", "moderator", "staff", "null", "undefined", "username", "test", "you", "me", "ploub", "boulon", "bebou", "sniflou", "grozinzin", "troupoutte", "flaplap", "koulou", "krousti", "mistouch", "marc", "coussi", "zoupla", "prouton", "zip", "chodron", "zarma", "gribouille"
]

def validate_avatar(image):
	max_size = 2 * 1024 * 1024 # max avatar size = 2MB

	if image.size > max_size:
		raise ValidationError(_("Avatar is too large (max %(max_size)s).") % {'max_size' : filesizeformat(max_size)})
		# raise ValidationError(f"Avatar is too large (max {filesizeformat(max_size)}).")

	try:
		img = Image.open(image)
		img.verify() # checks if it is really an image
		format = img.format.lower()
		if format not in ['jpeg', 'png']:
			raise ValidationError(_("Unsuported image format. Only JPEG and PNG allowed."))
	except Exception:
		raise ValidationError(_("Invalide image file."))


def validate_not_banned_username(value):
	if value.lower() in BANNED_USERNAMES:
	 	raise ValidationError(
            _('Forbiden username.'),
            params={'value': value},
        )	
	
def validate_min_username_length(value):
    if len(value) < 3:
        raise ValidationError(
            _('Username must be at least 3 characters long.'),
            params={'value': value},
        )