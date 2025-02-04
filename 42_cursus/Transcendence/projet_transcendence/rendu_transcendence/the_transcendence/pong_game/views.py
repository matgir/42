# from django.shortcuts import render
from django.http import HttpResponse
from rest_framework.permissions import IsAuthenticated
from rest_framework.response import Response
from rest_framework.views import APIView
from rest_framework import status

# Create your views here.

def	pong_game(request):
	return HttpResponse("Hello, this will be the pong game.")

class ProtectedView(APIView):
	permission_classes = [IsAuthenticated]

	def get(self,request):
		# print("Headers: ", request.headers)
		return Response({"message": "This view is protected"})
		# return Response({"message": "This view is protected"}, status=status.HTTP_200_OK)