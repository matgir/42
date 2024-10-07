all: build
	# bien delete ces dossier et les recreer
	docker compose -f ./srcs/docker-compose.yml up

install:
	sudo apt-get update
	sudo apt-get upgrade -y
	# sudo apt-get install -y curl gnupg ca-certificates lsb-release docker.io wmdocker docker-compose
	mkdir -p /home/$$USER/data /home/$$USER/data/db /home/$$USER/data/wp

build: install
	# mkdir -p /home/$$USER/data /home/$$USER/data/db /home/$$USER/data/wp
	docker compose -f ./srcs/docker-compose.yml up -d --build

clean:
	-docker compose -f ./srcs/docker-compose.yml pause
	-docker compose -f ./srcs/docker-compose.yml stop
	-docker compose -f ./srcs/docker-compose.yml down
	-docker stop $$(docker ps -aq)
	-docker rm -f $$(docker ps -aq)
	-docker rmi -f $$(docker image ls -aq)
	-docker volume rm $$(docker volume ls -q)
	# -rm -rf -r /home/$$USER/data /home/$$USER/data/db /home/$$USER/data/wp
	-sudo rm -rf -r /home/$$USER/data /home/$$USER/data/db /home/$$USER/data/wp
	docker system prune
	# docker system prune

re: clean all

.PHONY:	all install build clean re