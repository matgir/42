FROM python:3.13-alpine3.19
# from image python (to run python applications) and alpine (lighweight linux)

RUN mkdir /app
# create the app directory

WORKDIR /app
# set the working directory inside the container

# set the environment variables
ENV PYTHONDONTWRITEBYTECODE=1
# prevents python from writting pyc files to disk
ENV PYTHONUNBUFFERED=1
# prevents python from buffering stdout and stderr

RUN pip install --upgrade pip
# upgrade pip

COPY requirements.txt /app/
# copy the django project and install dependencies

RUN pip install --no-cache-dir -r requirements.txt
# run this command to install all dependencies

RUN apk update && apk upgrade && apk add --no-cache postgresql-client
# may erase it later, needed to check postgresql connection

COPY . /app/
# copy the django project to the container

EXPOSE 8000
# expose the django port

ENTRYPOINT ["sh", "run.sh"]
# run the django's development server

