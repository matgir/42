all:
	docker compose up -d --build
	docker compose start

prune:
	dockerbyby.sh

reprune: prune all

.PHONY: all prune reprune