all: build
	docker compose -f ./Inception_bis/srcs/docker-compose.yml start

setup:
	sudo apt-get update
	sudo apt-get upgrade -y
# sudo apt-get install -y curl gnupg ca-certificates lsb-release docker.io wmdocker docker-compose
	mkdir -p /home/$$USER/data /home/$$USER/data/db /home/$$USER/data/website
# mkdir -p /home/$$USER/data /home/$$USER/data/db /home/$$USER/data/website /home/$$USER/data/usefull_nginx

build: setup
# mkdir -p /home/$$USER/data /home/$$USER/data/db /home/$$USER/data/website
# sudo openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /home/mateo/Desktop/Inception/rendu_inception/Inception_bis/srcs/requirements/nginx/tools/nginx-selfsigned.key -out /home/mateo/Desktop/Inception/rendu_inception/Inception_bis/srcs/requirements/nginx/tools/nginx-selfsigned.crt -subj '/C=FR/ST=Ile-de-France/L=Paris/O=42/OU=42Paris/CN=MGIRARDO/UID=TTT'
# sudo chmod 600 /home/mateo/Desktop/Inception/rendu_inception/Inception_bis/srcs/requirements/nginx/tools/nginx-selfsigned.key
# sudo chmod 644 /home/mateo/Desktop/Inception/rendu_inception/Inception_bis/srcs/requirements/nginx/tools/nginx-selfsigned.crt
# sudo chown root:root /home/mateo/Desktop/Inception/rendu_inception/Inception_bis/srcs/requirements/nginx/tools/nginx-selfsigned.key
	docker compose -f ./Inception_bis/srcs/docker-compose.yml up -d --build

down:
	-docker compose -f ./Inception_bis/srcs/docker-compose.yml pause
	-docker compose -f ./Inception_bis/srcs/docker-compose.yml stop
	-docker compose -f ./Inception_bis/srcs/docker-compose.yml down

purge: down
	-docker stop $$(docker ps -aq)
	-docker rm -f $$(docker ps -aq)
	-docker rmi -f $$(docker image ls -aq)
	-docker volume rm $$(docker volume ls -q)
	-docker network rm $$(docker network ls -q)
# -rm -rf -r /home/$$USER/data /home/$$USER/data/db /home/$$USER/data/website
# -sudo rm -rf -r /home/$$USER/data /home/$$USER/data/db /home/$$USER/data/website /home/$$USER/data/usefull_nginx
	-sudo rm -rf -r /home/$$USER/data /home/$$USER/data/db /home/$$USER/data/website
	docker system prune
# docker system prune

re: purge all

.PHONY:	all setup build down purge re