all: build start

build:
	-mkdir -p -v lets_see/media/avatars
	docker compose -f docker-compose-prod.yml up -d --build

start:
	docker compose -f docker-compose-prod.yml start

stop:
	docker compose -f docker-compose-prod.yml stop

restart: stop start

rebuildstart: stop all

prune:
	rm -rf lets_see/media/avatars
	rm -rf lets_see/staticfiles
	-docker stop $$(docker ps -aq)
	-docker rm -f $$(docker ps -aq)
	-docker rmi -f $$(docker image ls -aq)
	-docker volume rm $$(docker volume ls -q)
	-docker network rm $$(docker network ls -q)
	docker system prune -af

reprune: prune all


.PHONY: all  build  start stop restart rebuildstart prune reprune
