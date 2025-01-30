all: build start

build:
	docker compose up -d --build

start:
	docker compose start

stop:
	docker compose stop

prune:
	dockerbyby.sh

reprune: prune all

.PHONY: all prune reprune build start stop