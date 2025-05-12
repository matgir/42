FROM debian:bullseye

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install unzip php curl wget redis php-redis php-mysqli php-fpm php-cgi -y
RUN apt-get install php-curl php-gd php-xml php-xmlrpc php-soap php-intl php-zip -y
RUN apt-get update && \
    apt-get install -y lsb-release apt-transport-https ca-certificates wget gnupg2 software-properties-common
RUN echo "deb https://packages.sury.org/php/ bullseye main" | tee /etc/apt/sources.list.d/sury-php.list && \
		wget -qO - https://packages.sury.org/php/apt.gpg | apt-key add -
RUN apt-get update
RUN apt-get install -y php8.0 php8.0-fpm php8.0-mysql default-mysql-client
RUN php -v && php-fpm8.0 -v


COPY ./conf/www.conf /etc/php/8.0/fpm/pool.d/	
COPY ./conf/wp-config.php /var/www/wordpress/wp-config.php

RUN mkdir /run/php

COPY ./tools/install.sh /home/
RUN chmod 777 /home/install.sh
COPY ./tools/index.php /etc/www/html/wordpress/index.php

EXPOSE 9000

ENTRYPOINT [ "/home/install.sh" ]