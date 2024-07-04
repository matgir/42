FROM debian:bullseye

RUN apt-get update -y

RUN apt-get upgrade -y

RUN apt-get -y install wget
	# wget (World Wild Web Get) allorws to retrieve content from web servers via HTTP HTTPS FTP protocols

RUN apt-get install -y php7.3 php-fpm php-mysql mariadb-client
	# instal PHP and its dependencies, PHP talks simply to the server web and set it up dinamicallyvia HTTP

RUN wget https://fr.wordpress.org/wordpress-6.5.4-fr_FR.tar.gz -P /var/www
	# download wordpress

RUN cd /var/www/
#RUN tar -xzf wordpress-6.5.4-fr_FR.tar.gz
#RUN rm wordpress-6.5.4-fr_FR.tar.gz
#RUN cd -
	# all this to un-tar the wordpress download

#RUN chown -R root:root /var/www/wordpress
	# change the owner of wordpress to root

#COPY conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf
#COPY conf/wp-config.php /var/www/wordpress/wp-config-sample.php

#RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
	# install the CLI nedeed to setup wordpress

#RUN chmod +x wp-cli.phar
	# gives the proper right to the document

#RUN mv wp-cli.phar /usr/local/bin/wp
	# so that it can be used as an executable

#COPY tools/script_wordpress.sh /usr/local/bin/

#RUN chmod 777 /usr/local/bin/script_wordpress.sh

#maybe create /run/php here

#ENTRYPOINT [ "/usr/local/bin/script_wordpress.sh" ]
