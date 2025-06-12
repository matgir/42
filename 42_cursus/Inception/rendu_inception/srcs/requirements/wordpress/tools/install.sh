#!/bin/sh
FILE=wordpress
cd /var/www/html

sleep 10

if [ -d "/var/www/html/$FILE" ]; then
	echo "$FILE exists."
else
	echo "$FILE does not exist."
	mkdir -p wordpress
	cd wordpress
	curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
	php wp-cli.phar --info
	chmod +x wp-cli.phar
	mv wp-cli.phar /usr/local/bin/wp
	wp core download --allow-root

	sleep 5
	wp config create --dbname=$DB_DATABASE --dbuser=$DB_USER --dbpass=$DB_PASSWORD --dbhost=$DB_HOST --allow-root
	sleep 5

	wp core install --url=$WP_URL --title=$WP_TITLE --admin_user=$WP_ADMIN_USER --admin_password=$WP_ADMIN_PASSWORD --admin_email=$WP_ADMIN_MAIL --allow-root
	wp user create $WP_USER $WP_USER_MAIL --user_pass=$WP_USER_PASSWORD --role=$WP_USER_ROLE --porcelain --allow-root
	wp theme install astra --activate --allow-root

	echo "END"
fi

/usr/sbin/php-fpm8.0 -F