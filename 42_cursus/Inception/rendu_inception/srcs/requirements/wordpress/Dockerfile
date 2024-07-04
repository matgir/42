FROM debian:bullseye

RUN apt-get update -y

RUN apt-get upgrade -y

RUN apt-get -y install wget
	# wget (World Wild Web Get) allorws to retrieve content from web servers via HTTP HTTPS FTP protocols

RUN apt-get install -y php7.3 php-fpm php-mysql mariadb-client
	# instal PHP and its dependencies, PHP talks simply to the server web and set it up dinamicallyvia HTTP

RUN wget https://fr.wordpress.org/wordpress-6.5.4-fr_FR.tar.gz -P /var/www
	# download wordpress

RUN cd /var/www
RUN tar -xzf wordpress-6.5.4-fr_FR.tar.gz
RUN rm wordpress-6.5.4-fr_FR.tar.gz
	# all this to un-tar the wordpress download

RUN chown -R root:root /var/www/wordpress
	# change the owner of wordpress to root

COPY conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf
