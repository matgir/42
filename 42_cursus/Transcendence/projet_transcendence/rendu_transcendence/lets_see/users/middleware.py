from django.utils import translation

class UserLanguageMiddleware:
	def __init__(self, get_response):
		self.get_response = get_response

	def __call__(self, request):
		if hasattr(request, 'user') and request.user.is_authenticated:
			lang = request.user.preferred_language
			translation.activate(lang)
			request.LANGUAGE_CODE = lang

		response = self.get_response(request)
		translation.deactivate()
		return response