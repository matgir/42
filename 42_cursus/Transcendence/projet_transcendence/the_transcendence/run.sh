#!/bin/sh

# cd djangotutorial

# ls -la

python manage.py makemigrations
python manage.py migrate
python manage.py runserver 8800