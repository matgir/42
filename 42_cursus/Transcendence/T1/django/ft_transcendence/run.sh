#!/bin/sh

python3 manage.py makemigrations core
python3 manage.py makemigrations game
python3 manage.py makemigrations chat
python3 manage.py migrate
echo 'yes' | python3 manage.py collectstatic
daphne -b 0.0.0.0 -p 8000 ft_transcendence.asgi:application
# python3 manage.py runserver 0.0.0.0:8000

