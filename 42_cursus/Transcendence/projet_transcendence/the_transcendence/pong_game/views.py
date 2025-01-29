# from django.shortcuts import render
from django.http import HttpResponse

# Create your views here.

def	pong_game(request):
	return HttpResponse("Hello, this will be the pong game.")