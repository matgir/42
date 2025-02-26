all: build start
	mkdir -p media/users_avatars

build:
	docker compose up -d --build

start:
	docker compose start

stop:
	docker compose stop

restart: stop start

rebuildstart: stop all

prune:
	-docker stop $$(docker ps -aq)
	-docker rm -f $$(docker ps -aq)
	-docker rmi -f $$(docker image ls -aq)
	-docker volume rm $$(docker volume ls -q)
	-docker network rm $$(docker network ls -q)
	docker system prune -af

reprune: prune all

.PHONY: all build start stop restart rebuildstart prune reprune