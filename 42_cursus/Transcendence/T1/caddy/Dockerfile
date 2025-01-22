FROM caddy:2-alpine

RUN apk add tzdata
RUN ln -s /usr/share/zoneinfo/Europe/Brussels /etc/localtime

COPY Caddyfile /etc/caddy/Caddyfile

WORKDIR "/etc/caddy/"

CMD ["caddy", "run"]
