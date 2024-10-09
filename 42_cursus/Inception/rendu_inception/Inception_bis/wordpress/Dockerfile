FROM debian:buster

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install php-fpm -y


COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/

RUN mkdir /run/php

COPY ./conf/index.php /etc/www/html/wordpress/index.php

EXPOSE 9000

ENTRYPOINT [ "/usr/sbin/php-fpm7.3", "-F" ]