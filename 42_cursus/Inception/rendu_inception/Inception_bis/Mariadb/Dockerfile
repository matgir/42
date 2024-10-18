# Specifies the base image on wich we are going to create our container
FROM debian:buster

# Updates and install the tools we need
RUN apt-get update
# the <-y> is used to answer yes when bash asks use to validate the instalation
RUN apt install -y mariadb-server

# It will copy our configuration file in the container, used for the bind and
# the SQL script
COPY 50-server.cnf /etc/mysql/mariadb.conf.d/

# Copy the script in the container and modify execution rights
COPY script.sh /
RUN chmod +x /script.sh

ENTRYPOINT [ "/script.sh" ]