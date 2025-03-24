#!/bin/sh

# cd djangotutorial

# ls -la


python manage.py makemigrations users
python manage.py migrate

# echo "from users.models import CustomUser; import os; user=os.getenv('DJANGO_SUPERUSER'); email=os.getenv('DJANGO_SUPERUSER_EMAIL'); password=os.getenv('DJANGO_SUPERUSER_PASS'); if not CustomUser.objects.filter(username=user).exists(): CustomUser.objects.create_superuser(username,email,password)" | python manage.py shell
echo "from users.models import CustomUser; import os; CustomUser.objects.create_superuser(os.getenv('DJANGO_SUPERUSER'), os.getenv('DJANGO_SUPERUSER_EMAIL'), os.getenv('DJANGO_SUPERUSER_PASS'))" | python manage.py shell

python manage.py makemigrations users
python manage.py makemigrations tournament
python manage.py makemigrations
python manage.py migrate

# python manage.py runserver 0.0.0.0:8000
daphne -b 0.0.0.0 -p 8000 lets_see.asgi:application
# python manage.py test


