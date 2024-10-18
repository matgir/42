FROM debian:buster

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install unzip php curl wget redis php-redis php-mysqli php-fpm php-cgi -y
RUN apt-get install php-curl php-gd php-mbstring php-xml php-xmlrpc php-soap php-intl php-zip -y
RUN apt-get install default-mysql-client -y

COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/
COPY ./conf/wp-config.php /var/www/wordpress/wp-config.php

RUN mkdir /run/php

COPY ./tools/install.sh /home/
RUN chmod 777 /home/install.sh
# COPY ./conf/index.php /etc/www/html/wordpress/index.php

EXPOSE 9000

ENTRYPOINT [ "/home/install.sh" ]
# ENTRYPOINT [ "/usr/sbin/php-fpm7.3", "-F" ]