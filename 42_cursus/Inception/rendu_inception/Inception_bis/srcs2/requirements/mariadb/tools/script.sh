#!/bin/sh

service mysql start

# Create user
echo "CREATE USER '$DB_USER'@'%' IDENTIFIED BY '$DB_PASSWORD';" | mysql

# Grant privileges for root and user for all IP address
echo "GRANT ALL PRIVILEGES ON *.* TO '$DB_USER'@'%' IDENTIFIED BY '$DB_PASSWORD';" | mysql
echo "GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' IDENTIFIED BY '$DB_ROOT_PASSWORD';" | mysql
echo "FLUSH PRIVILEGES;" | mysql

# Create wordpress database
echo "CREATE DATABASE $DB_DATABASE;" | mysql

kill $(cat /var/run/mysqld/mysqld.pid)

mysqld