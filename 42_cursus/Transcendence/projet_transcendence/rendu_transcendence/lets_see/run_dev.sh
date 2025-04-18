#!/bin/sh

python3 manage.py makemigrations users
python3 manage.py migrate

# echo "from users.models import CustomUser; import os; user=os.getenv('DJANGO_SUPERUSER'); email=os.getenv('DJANGO_SUPERUSER_EMAIL'); password=os.getenv('DJANGO_SUPERUSER_PASS'); if not CustomUser.objects.filter(username=user).exists(): CustomUser.objects.create_superuser(username,email,password)" | python3 manage.py shell
echo "from users.models import CustomUser; import os; CustomUser.objects.create_superuser(os.getenv('DJANGO_SUPERUSER'), os.getenv('DJANGO_SUPERUSER_EMAIL'), os.getenv('DJANGO_SUPERUSER_PASS'))" | python3 manage.py shell

python3 manage.py makemigrations users
python3 manage.py makemigrations tournament
python3 manage.py makemigrations
python3 manage.py migrate

# echo 'yes' | python3 manage.py collectstatic

daphne -b 0.0.0.0 -p 8000 lets_see.asgi:application
# python3 manage.py runserver 0.0.0.0:8000


