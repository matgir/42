all:
	mkdir -p /home/$$USER/data /home/$$USER/data/db /home/$$USER/data/wp
	# bien delete ces dossier et les recreer
	docker compose -f ./srcs/docker-compose.yml up

install:
	apt-get update
	apt-get upgrade -y
	apt-get install -y curl gnupg ca-certificates lsb-release docker.io docker docker-compose
	mkdir -p /home/$$USER/data /home/$$USER/data/db /home/$$USER/data/wp

build:	all
	docker compose -f ./srcs/docker-compose.yml up -d --build

clean:
	# docker compose -f ./srcs/docker-compose.yml pause
	# docker compose -f ./srcs/docker-compose.yml stop
	# docker compose -f ./srcs/docker-compose.yml down
	sudo rm -rf -r /home/$$USER/data /home/$$USER/data/db /home/$$USER/data/wp
	docker system prune
	# docker stop -f $$(sudo docker ps -aq)
	docker rmi -f $$(docker image ls -aq)
	docker system prune
	docker rm -f $$(sudo docker ps -aq)

re: clean all