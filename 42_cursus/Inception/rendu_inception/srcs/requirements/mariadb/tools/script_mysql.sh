#!/bin/sh

# mkdir -p /run/mysqld
# chown -R mysql:mysql /run/mysqld
# service mysql start
echo "Mariadb Starting..."
service mariadb start
	#	starts mysql
sleep 2
	# allow mysql to start
echo 10
mysql -e "CREATE DATABASE IF NOT EXISTS \`${DB_DATABASE}\`;"
	#	creates a table if it does not exists with ${DB_DATABEASE} name indicated in .env
sleep 1
echo 2
mysql -e "CREATE USER IF NOT EXISTS \`${DB_USER}\`@'localhost' IDENTIFIED BY '${DB_PASSWORD}';"
	#	creates user if not existing already with specified password from .env
echo 3
sleep 1
mysql -e "GRANT ALL PRIVILEGES ON \`${DB_DATABASE}\`.* TO \`${DB_USER}\`@'%' IDENTIFIED BY '${DB_PASSWORD}';"
	#	grants all privileges on database to the created user
echo 4
sleep 1
mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD}';"
	#	here changes the root password to ${DB_ROOT_PASSWORD} from .env
echo 5
# trouver un moyen de se connecter en root puis fluch privileges
sleep 1
mysql -u root -p${DB_ROOT_PASSWORD} -e "FLUSH PRIVILEGES"
# mysql -e "FLUSH PRIVILEGES"
	#	update the last changes in mysql
echo 6
sleep 1
mysqladmin -u root -p${DB_ROOT_PASSWORD} shutdown
	#	reboot mysql
echo 7
exec mysqld_safe
	#	command that mysql ask at start
