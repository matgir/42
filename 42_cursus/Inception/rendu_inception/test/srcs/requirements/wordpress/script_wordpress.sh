# #!bin/bash

# sleep 10

# cd /var/www/wordpress

# # automatic configuration for the wordpress website
# wp core config	--dbhost=$DB_HOST \
# 				--dbname=$DB_DATABASE \
# 				--dbuser=$DB_USER \
# 				--dbpass=$DB_PASSWORD \
# 				--path='/var/www/wordpress' \
# 				--allow-root

# # add admin user
# wp core install	--title=$WP_TITLE \
# 				--admin_user=$WP_ADMIN_USER \
# 				--admin_password=$WP_ADMIN_PASSWORD \
# 				--admin_mail=$WP_ADMIN_MAIL \
# 				--url=$WP_URL \
# 				--allow-root

# # add classic user
# wp user create	$WP_USER \
# 				$WP_USER_MAIL \
# 				--role=author \
# 				--user_pass=$WP_USER_PASSWORD \
# 				--allow-root

# cd -

# # run php-fpm7.3 listening for CGI request
# php-fpm7.3 -F

#!/bin/bash

if [ ! -e "/var/www/html/wp-config.php" ]; then
        sleep 20

        wp core download --path=/var/www/html --allow-root

        wp config create --path=/var/www/html --dbname=$DB_DATABASE --dbuser=$DB_USER --dbpass=$DB_PASSWORD --dbhost=$DB_HOST --allow-root


        wp core install --path=/var/www/html --url=$WP_URL --title=$WP_TITLE --admin_user=$WP_ADMIN_USER --admin_password=$WP_ADMIN_PASSWORD --admin_email=$WP_ADMIN_MAIL --allow-root

        wp user create --path=/var/www/html $WP_USER $WP_USER_MAIL --user_pass=$WP_USER_PASSWORD --role=editor --allow-root

else
        sleep 3
        echo Wordpress already installed, installation step skipped
fi

exec php-fpm7.3 -F -R --nodaemonize