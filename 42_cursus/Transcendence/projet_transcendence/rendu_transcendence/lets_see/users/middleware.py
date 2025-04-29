from django.utils import translation
from django.conf import settings

class UserLanguageMiddleware:
	def __init__(self, get_response):
		self.get_response = get_response

	def __call__(self, request):
		response = self.get_response(request)

		if hasattr(request, 'user') and request.user.is_authenticated:
			lang = getattr(request.user, 'preferred_language', None)
			if lang:
				request.session['django_language'] = lang
				translation.activate(lang)
				response.set_cookie(settings.LANGUAGE_COOKIE_NAME, lang)

		# translation.deactivate()
		return response