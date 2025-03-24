all: build_prod start_prod
	docker compose -f docker-compose-prod.yml logs -f --timestamps 
# show the logs of the docker in real time with the timestamp

dev: build_dev start_dev
	docker compose -f docker-compose-dev.yml logs -f --timestamps

build_prod:
	-mkdir lets_see/media/avatars
	docker compose -f docker-compose-prod.yml up -d --build

build_dev:
	-mkdir lets_see/media/avatars
	docker compose -f docker-compose-dev.yml up -d --build

start_prod:
	docker compose -f docker-compose-prod.yml start
	docker compose -f docker-compose-prod.yml logs -f --timestamps

start_dev:
	docker compose -f docker-compose-dev.yml start
	docker compose -f docker-compose-dev.yml logs -f --timestamps

stop_prod:
	docker compose -f docker-compose-prod.yml stop

stop_dev:
	docker compose -f docker-compose-dev.yml stop

restart_prod: stop_prod start_prod

restart_dev: stop_dev start_dev

rebuildstart_prod: stop_prod all

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