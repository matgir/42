#!/bin/sh

cd djangotutorial

ls -la

python manage.py migrate
python manage.py runserver 0.0.0.0:8880