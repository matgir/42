from allauth.socialaccount.adapter import get_adapter
from allauth.socialaccount.providers.oauth2.views import (
	OAuth2Adapter,
	OAuth2CallbackView,
	OAuth2LoginView,
)

FT_API_BASE_URL = "https://api.intra.42.fr"

class FortytwoOAuth2Adapter(OAuth2Adapter):
	provider_id = 'fortytwo'
	access_token_url = f'{FT_API_BASE_URL}/oauth/token'
	authorize_url = f'{FT_API_BASE_URL}/oauth/authorize'
	profile_url = f'{FT_API_BASE_URL}/v2/me'

	def get_callback_url(self, request, app):
		callback_url = super().get_callback_url(request, app)
		print("Callback URL being sent to 42 API:", callback_url)
		return callback_url

	def complete_login(self, request, app, token, **kwargs):
		headers = {
			"Authorization": "Bearer {0}".format(token.token),
			"Content-Type": "application/json",
		}
		extra_data = (
			get_adapter().get_requests_session().get(self.profile_url, headers=headers)
		)
		return self.get_provider().sociallogin_from_response(request, extra_data.json())

oauth2_login = OAuth2LoginView.adapter_view(FortytwoOAuth2Adapter)
oauth2_callback = OAuth2CallbackView.adapter_view(FortytwoOAuth2Adapter)