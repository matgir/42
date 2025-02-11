#!/bin/sh

# cd djangotutorial

# ls -la


python manage.py makemigrations
python manage.py makemigrations users
python manage.py migrate

# echo "from users.models import PongUser; import os; user=os.getenv('DJANGO_SUPERUSER'); email=os.getenv('DJANGO_SUPERUSER_EMAIL'); password=os.getenv('DJANGO_SUPERUSER_PASS'); if not PongUser.objects.filter(username=user).exists(): PongUser.objects.create_superuser(username,email,password)" | python manage.py shell
echo "from users.models import PongUser; import os; PongUser.objects.create_superuser(os.getenv('DJANGO_SUPERUSER'), os.getenv('DJANGO_SUPERUSER_EMAIL'), os.getenv('DJANGO_SUPERUSER_PASS'))" | python manage.py shell

python manage.py runserver 0.0.0.0:8000
# python manage.py test

# python manage.py makemigrations users

# docker-compose exec web python manage.py shell -c "from users.models import PongUser; import os; user=os.getenv('DJANGO_SUPERUSER'); email=os.getenv('DJANGO_SUPERUSER_EMAIL'); pwd=os.getenv('DJANGO_SUPERUSER_PASS'); \
# if not PongUser.objects.filter(username=user).exists(): PongUser.objects.create_superuser(user, email, pwd)"
