#!/bin/sh

# service mysql start
mysqld_safe &
	#	starts mysql
sleep 5
	# allow mysql to start
mysql -e "CREATE DATABASE IF NOT EXISTS \`${DB_DATABASE}\`;"
	#	creates a table if it does not exists with ${DB_DATABEASE} name indicated in .env
mysql -e "CREATE USER IF NOT EXISTS \`${DB_USER}\`@'localhost' IDENTIFIED BY '${DB_PASSWORD}';"
	#	creates user if not existing already with specified password from .env
mysql -e "GRANT ALL PRIVILEGES ON \`${DB_DATABASE}\`.* TO \`${DB_USER}\`@'%' IDENTIFIED BY '{DB_PASSWORD}';"
	#	grants all privileges on database to the created user
mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD}';"
	#	here changes the root password to ${DB_ROOT_PASSWORD} from .env
mysql -e "FLUSH PRIVILEGES"
	#	update the last changes in mysql
mysqladmin -u root -p${DB_ROOT_PASSWORD} shutdown
	#	reboot mysql
exec mysqld_safe
	#	command that mysql ask at start
