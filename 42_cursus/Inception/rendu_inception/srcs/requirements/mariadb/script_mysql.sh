
# service mysql start
# 	#	starts mysql
# mysql -e "CREATE DATABASE IF NOT EXISTS \`${DB_DATABASE}\`;"
# 	#	creates a table if it does not exists with ${DB_DATABEASE} name indicated in .env
# mysql -e "CREATE USER IF NOT EXISTS \`${DB_USER}\`@'localhost' IDENTIFIED BY '${DB_PASSWORD}';"
# 	#	creates user if not existing already with specified password from .env
# mysql -e "GRANT ALL PRIVILEGES ON \`${DB_DATABASE}\`.* TO \`${DB_USER}\`@'%' IDENTIFIED BY '{DB_PASSWORD}';"
# 	#	grants all privileges on database to the created user
# mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD}';"
# 	#	here changes the root password to ${DB_ROOT_PASSWORD} from .env
# mysql -e "FLUSH PRIVILEGES"
# 	#	update the last changes in mysql
# mysqladmin -u root -p$DB_ROOT_PASSWORD shutdown
# 	#	reboot mysql
# exec mysqld_safe
# 	#	command that mysql ask at start


# service mysql start;
# mysql -e "CREATE DATABASE IF NOT EXISTS \`${SQL_DATABASE}\`;"
# mysql -e "CREATE USER IF NOT EXISTS \`${SQL_USER}\`@'localhost' IDENTIFIED BY '${SQL_PASSWORD}';"
# mysql -e "GRANT ALL PRIVILEGES ON \`${SQL_DATABASE}\`.* TO \`${SQL_USER}\`@'%' IDENTIFIED BY '${SQL_PASSWORD}';"
# mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';"
# mysql -e "FLUSH PRIVILEGES;"
# mysqladmin -u root -p$SQL_ROOT_PASSWORD shutdown
# exec mysqld_safe

#!/bin/sh
service mysql start 

# CREATE USER #
echo "CREATE USER '$DB_USER'@'%' IDENTIFIED BY '$DB_PASSWORD';" | mysql

# PRIVILGES FOR ROOT AND USER FOR ALL IP ADRESS #
echo "GRANT ALL PRIVILEGES ON *.* TO '$DB_USER'@'%' IDENTIFIED BY '$DB_PASSWORD';" | mysql
echo "GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' IDENTIFIED BY '$DB_ROOT_PASSWORD';" | mysql
echo "FLUSH PRIVILEGES;" | mysql

# CREAT WORDPRESS DATABASE #
echo "CREATE DATABASE $DB_DATABASE;" | mysql

kill $(cat /var/run/mysqld/mysqld.pid)

mysqld