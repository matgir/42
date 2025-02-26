# from django.shortcuts import render
# from rest_framework_simplejwt.views import TokenObtainPairView, TokenRefreshView
# from rest_framework import status
# from rest_framework.response import Response
# from rest_framework.views import APIView
# from rest_framework.permissions import AllowAny
# # from .serializers import CustomTokenObtainPairSerializer, UserSerializer

# # class CustomTokenObtainPairView(TokenObtainPairView):
# # 	serializer_class = CustomTokenObtainPairSerializer
# # thie handles the creation of both access and refresh tokens when a user logs in

# class CustomTokenRefreshView(TokenRefreshView):
# 	pass
# # this view is responseble for refreshing access tokens using a valid refresh token

# class RegisterView(APIView):
# 	permission_classes = [AllowAny]

# 	def post(self, request):
# 		serializer = UserSerializer(data=request.data)
# 		if serializer.is_valid():
# 			user = serializer.save()
# 			if user:
# 				json = serializer.data
# 				return Response(json, status=status.HTTP_201_CREATED)
# 		return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)
# # this custom view allows new users to register
