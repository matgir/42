from rest_framework_simplejwt.serializers import TokenObtainPairSerializer
from rest_framework import serializers
from .models import CustomUser

class CustomTokenObtainPairSerializer(TokenObtainPairSerializer):
	@classmethod
	def get_token(cls, user):
		token = super().get_token(user)
		# add custom claims
		token['email'] = user.email
		""" here you can add any other info the the JWT token payload
		toke['roles'] = list(user.groups.values_list('name', flat=True)) """
		return token
# allows us to add custom claims to the token payload, here adding user's email

class UserSerializer(serializers.ModelSerializer):
	password = serializers.CharField(write_only=True)

	class Meta:
		model = CustomUser
		fields = ('email', 'username', 'password')

	def create(self, validated_data):
		user = CustomUser.objects.create_user(
			email=validated_data['email'],
			username=validated_data['username'],
			password=validated_data['password']
		)
		return user
# used for user registration, ensuring that the password is write only
# and not returned in responses