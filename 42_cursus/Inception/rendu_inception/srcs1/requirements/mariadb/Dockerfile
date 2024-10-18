FROM debian:bullseye

RUN apt update -y

RUN apt upgrade -y

RUN apt-get install mariadb-server -y

RUN apt install vim -y

COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/

COPY tools/script_mysql.sh /usr/local/bin/

RUN chmod +x /usr/local/bin/script_mysql.sh

# ENV DB_DATABASE=wordpress 	
# ENV DB_USER=mgirardo 
# ENV DB_PASSWORD=introuvable
# ENV DB_ROOT_PASSWORD=pasmoi
# ENV DB_HOST=mariadb:3306


ENTRYPOINT [ "/usr/local/bin/script_mysql.sh" ]

# # SPECIFIES DISTRIBUTION
# FROM debian:bullseye

# # UPDATE AND INSTALLATION
# RUN apt-get update
# RUN apt install -y mariadb-server 

# # COPY THE CONF FOR THE BIND AND THE SQL SCRIPT FOR THE PRIVILEGE
# COPY 50-server.cnf /etc/mysql/mariadb.conf.d/

# # COPY THE SCRIPT IN THE IMAGES AND MODIFY THE EXECUTION RIGHTS OF IT
# COPY tools/script_mysql.sh /
# RUN chmod +x /script_mysql.sh

# ENTRYPOINT [ "/script_mysql.sh" ]