from django.db.models import F
from django.http import HttpResponse, HttpResponseRedirect
# from django.template import loader
from django.shortcuts import get_object_or_404, render
# from django.http import Http404
from django.urls import reverse
from django.views import generic
from django.utils import timezone

from .models import Choice, Question

# Create your views here.

""" def index(request):
	latest_question_list = Question.objects.order_by("-pub_date")[:5]
	# template = loader.get_template("polls/index.html")
	context = {
		"latest_question_list": latest_question_list,
	}
	return render(request, "polls/index.html", context) """
class IndexView(generic.ListView):
	template_name = "polls/index.html"
	context_object_name = "latest_question_list"

	def get_queryset(self):
		""" return the last five published questions (not including those set to
		be published in the future). """
		# return Question.objects.order_by("-pub_date")[:5]
		return Question.objects.filter(pub_date__lte=timezone.now()).order_by("-pub_date")[:10]

""" def results(request, question_id):
	question = get_object_or_404(Question, pk=question_id)
	return render(request, "polls/results.html", {"question": question}) """
class ResultView(generic.DetailView):
	model = Question
	template_name = "polls/results.html"

def vote(request, question_id):
	question = get_object_or_404(Question, pk=question_id)
	try:
		selected_choice = question.choice_set.get(pk=request.POST["choice"])
	except (KeyError, Choice.DoesNotExist):
		# Redisplay the question voting form.
		return render(request, "polls/details.html", {
			"question": question,
			"error_message": "You did not select a choice.",
		},
	)
	else:
		selected_choice.votes = F("votes") + 1
		selected_choice.save()
		""" Always return an HttpResponseRedirect after successfully dealing with POST
		data. This prevents data from being posted twice if a user hits de back button """
		return HttpResponseRedirect(reverse("polls:results", args=(question.id,)))

""" def detail(request, question_id):
	question = get_object_or_404(Question, pk=question_id)
	return render(request, "polls/details.html", {"question": question}) """
class DetailView(generic.DetailView):
	model = Question
	template_name = "polls/details.html"

	def get_queryset(self):
		""" excludes any questions that are not published yet """
		return Question.objects.filter(pub_date__lte=timezone.now())
