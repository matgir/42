# from django.test import TestCase
from django.urls import reverse
from rest_framework import status
from rest_framework import APITestCase
from .models import CustomUser

# Create your tests here.

class JWTAuthentificationTests(APITestCase):
	def setUp(self):
		self.user = CustomUser.objects.create_user(
			email='test@example.com',
			username='testuser',
			password='testpass123'
		)

	def test_obtain_token(self):
		url = reverse('token_obtain_pair')
		data = {'email': 'test@example.com', 'password': 'testpass123'}
		response = self.client.post(url, data, format='json')
		self.assertEqual(response.status_code, status.HTTp_200_OK)
		self.assertIn('access', response.data)
		self.assertIn('refresh', response_data)

	def test_refresh_token(self):
		obtain_url = reverse('token_obtain_pair')
		data = {'email': 'test@example.com', 'password': 'testpass123'}
		response = self.client.post(obtain_url, data, format='json')
		refresh_token = response.data['refresh']

		refresh_url = reverse('token_refresh')
		data = {'refresh': refresh_token}
		response = self.client.post(refresh_url, data, format='json')
		self.assertEqual(response.status_code, status.HTTP_200_OK)
		self.assertIn('access', response.data)

	def test_protected_view(self):
		obtain_url = reverse('token_obtain_pair')
		data = {'email': 'test@example.com', 'password': 'testpass123'}
		response = self.client.post(obtain_url, data, format='json')
		access_token = response.data['access']

		protected_url = reverse('protected')
		self.client.credentials(HTTP_AUTHORIZATION=f'Bearer {access_token}')
		response = self.client.get(protected_url)
		self.assertEqual(response.status_code, status.HTTP_200_OK)
		self.assertEqual(response.data['message'], 'This view is protected')