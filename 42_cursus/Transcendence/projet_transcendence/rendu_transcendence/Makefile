all: build_prod start_prod
	docker compose -f docker-compose-prod.yml logs -f --timestamps 
# show the logs of the docker in real time with the timestamp

build_prod:
	-mkdir -p -v lets_see/media/avatars
	docker compose -f docker-compose-prod.yml up -d --build

start_prod:
	docker compose -f docker-compose-prod.yml start
	docker compose -f docker-compose-prod.yml logs -f --timestamps

stop_prod:
	docker compose -f docker-compose-prod.yml stop

restart_prod: stop_prod start_prod

rebuildstart_prod: stop_prod all

dev: build_dev start_dev
	docker compose -f docker-compose-dev.yml logs -f --timestamps

build_dev:
	-mkdir -p -v lets_see/media/avatars
	docker compose -f docker-compose-dev.yml up -d --build

start_dev:
	docker compose -f docker-compose-dev.yml start
	docker compose -f docker-compose-dev.yml logs -f --timestamps

stop_dev:
	docker compose -f docker-compose-dev.yml stop

restart_dev: stop_dev start_dev

rebuildstart_dev: stop_dev dev

prune:
	rm -rf lets_see/media/avatars
	-docker stop $$(docker ps -aq)
	-docker rm -f $$(docker ps -aq)
	-docker rmi -f $$(docker image ls -aq)
	-docker volume rm $$(docker volume ls -q)
	-docker network rm $$(docker network ls -q)
	docker system prune -af

reprune_prod: prune all

reprune_dev: prune dev

.PHONY: all dev build_prod build_dev start stop restart rebuildstart prune reprune