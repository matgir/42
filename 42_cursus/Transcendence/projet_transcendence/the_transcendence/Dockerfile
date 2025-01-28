FROM python:3.12-alpine3.19
# from image python (to run python applications) and alpine (lighweight linux)

COPY . /the_transcendence


# RUN python -m venv tutorial-env
# create a virtual environement

# RUN source tutorial-env/bin/activate
# activates the virtual environment

RUN python -m pip install django psycopg2-binary
# install django and necessary pack for postgresql

# RUN mkdir djangotutorial
# RUN django-admin startproject mysite djangotutorial

# RUN cd djangotutorial
WORKDIR /the_transcendence
RUN chmod +x run.sh
# COPY run.sh .

ENTRYPOINT [ "sh", "run.sh" ]