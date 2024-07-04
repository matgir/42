#!bin/bash

sleep 10

cd /var/www/wordpress

# automatic configuration for the wordpress website
wp core config	--dbhost=$DB_HOST \
				--dbname=$DB_DATABASE \
				--dbuser=$DB_USER \
				--dbpass=$DB_PASSWORD \
				--path='/var/www/wordpress' \
				--allow-root

# add admin user
wp core install	--title=$WP_TITLE \
				--admin_user=$WP_ADMIN_USER \
				--admin_password=$WP_ADMIN_PASSWORD \
				--admin_mail=$WP_ADMIN_MAIL \
				--url=$WP_URL \
				--allow-root

# add classic user
wp user create	$WP_USER \
				$WP_USER_MAIL \
				--role=author \
				--user_pass=$WP_USER_PASSWORD \
				--allow-root

cd -

# run php-fpm7.3 listening for CGI request
php-fpm7.3 -F