FROM python:3.12-alpine3.19
# from image python (to run python applications) and alpine (lighweight linux)

# RUN python -m venv tutorial-env
# create a virtual environement

# RUN source tutorial-env/bin/activate
# activates the virtual environment

RUN python -m pip install django
# install django

RUN mkdir djangotutorial
RUN django-admin startproject mysite djangotutorial

# RUN cd djangotutorial

COPY run.sh .

ENTRYPOINT [ "sh", "run.sh" ]