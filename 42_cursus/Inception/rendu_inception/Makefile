all: build
	docker compose -f ./srcs/docker-compose.yml start

update:
	-sudo apt-get update
	-sudo apt-get upgrade -y
	-sudo apt-get install -y curl gnupg ca-certificates lsb-release docker.io wmdocker docker-compose
	-sudo apt install mysql-client-core-8.0
	-sudo apt install mariadb-client-core

build:
	sudo mkdir -p /home/$$USER/data /home/$$USER/data/db /home/$$USER/data/wp
	docker compose -f ./srcs/docker-compose.yml up -d --build

pause:
	-docker compose -f ./srcs/docker-compose.yml pause

stop: pause
	-docker compose -f ./srcs/docker-compose.yml stop

down: stop
	-docker compose -f ./srcs/docker-compose.yml down

purge: down
	-docker stop $$(docker ps -aq)
	-docker rm -f $$(docker ps -aq)
	-docker rmi -f $$(docker image ls -aq)
	-docker volume rm $$(docker volume ls -q)
	-docker network rm $$(docker network ls -q)
	-sudo rm -rf -r /home/$$USER/data /home/$$USER/data/db /home/$$USER/data/wp
	docker system prune

re: purge all

.PHONY:	all update build pause stop down purge re