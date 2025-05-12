# from django.shortcuts import render
from django.http import HttpResponse
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework.permissions import IsAuthenticated

# Create your views here.

def	pong_game(request):
	return HttpResponse("Hello, this will be the pong game.")

class ProtectedView(APIView):
	permission_classes = [IsAuthenticated]

	def get(self, request):
		return Response({"message": "This view is protected"})