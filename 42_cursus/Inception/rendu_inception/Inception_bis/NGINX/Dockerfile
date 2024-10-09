FROM debian:buster

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install -y nginx openssl
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt -subj '/C=FR/ST=Ile-de-France/L=Paris/O=42/OU=42Paris/CN=MGIRARDO/UID=TTT'

# RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt -subj '/C=FR/ST=Ile-de-France/L=Paris/O=42/OU=42Paris/CN=TLIOT/UID=TTT'



RUN echo "ssl_certificate /etc/ssl/certs/nginx-selfsigned.crt;\nssl_certificate_key /etc/ssl/private/nginx-selfsigned.key;" > /etc/nginx/snippets/self_signed.conf
RUN openssl dhparam -out /etc/nginx/dhparam.pem 2048

COPY ./conf/ssl-param.conf /etc/nginx/snippets/

COPY ./conf/default /etc/nginx/sites-available/default

ENTRYPOINT [ "nginx", "-g", "daemon off;" ]