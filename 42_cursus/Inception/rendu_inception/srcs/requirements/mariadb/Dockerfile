FROM debian:bullseye

RUN apt update -y

RUN apt upgrade -y

RUN apt-get install mariadb-server -y

RUN apt install vim -y

COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

COPY tools/script_mysql.sh /usr/local/bin/

RUN chmod 777 /usr/local/bin/script_mysql.sh

#ENTRYPOINT [ "/usr/local/bin/script_mysql.sh" ]