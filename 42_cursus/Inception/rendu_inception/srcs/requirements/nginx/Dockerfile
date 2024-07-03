FROM debian:bullseye

RUN apt update -y
# 	check si tout est a jour
RUN apt upgrade -y
# 	upgrade au cas ou
RUN apt install nginx -y
# 	install nginx in my container

RUN apt install vim -y
# 	install vim in my container

RUN mkdir -p /etc/nginx/ssl
# 	creates the directory to store my certificate and key TSL

RUN apt install openssl -y
# 	install ssl tool

RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=login.42.fr/UID=mgirardo"
# 	creates the certificate	-x509 : selfsigned certificate
# 							-nodes : whithout mdp for the private key
# 							-out : where to put the certificate
# 							-keyout : where to put the key

RUN mkdir -p /var/run/nginx
# 	creates the directory for the config file of nginx

COPY conf/nginx.conf /etc/nginx/nginx.conf
# 	gets the file we have in our conf

RUN chmod 755 /var/www/html
RUN chown -R www-data:www-data /var/www/html
#	gives us access to the file we'll need

CMD ["nginx", "-g", "daemon off;"]