FROM debian:buster

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install -y nginx openssl
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt -subj '/C=FR/ST=Ile-de-France/L=Paris/O=42/OU=42Paris/CN=MGIRARDO/UID=TTT'
# COPY ./tools/nginx-selfsigned.key /etc/ssl/private/nginx-selfsigned.key
# COPY ./tools/nginx-selfsigned.key /etc/ssl/certs/nginx-selfsigned.crt
RUN chmod 600 /etc/ssl/private/nginx-selfsigned.key
RUN chown root:root /etc/ssl/private/nginx-selfsigned.key
# RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt -subj '/C=FR/ST=Ile-de-France/L=Paris/O=42/OU=42Paris/CN=TLIOT/UID=TTT'


RUN mkdir -p /etc/nginx/snippets
RUN touch /etc/nginx/snippets/self-signed.conf
RUN echo "ssl_certificate /etc/ssl/certs/nginx-selfsigned.crt;\nssl_certificate_key /etc/ssl/private/nginx-selfsigned.key;" > /etc/nginx/snippets/self_signed.conf
RUN openssl dhparam -out /etc/nginx/dhparam.pem 2048

COPY ./conf/ssl-params.conf /etc/nginx/snippets/

# COPY ./conf/default /etc/nginx/sites-available/default
COPY ./conf/default /etc/nginx/sites-available/
# COPY ./conf/adminer.conf /etc/nginx/sites-available/
# COPY ./conf/subdomain.conf /etc/nginx/sites-available/

# ln -s, creates a symbolic link/shortcut between the two docs, with this
# nginx will recognise and load the conf files
# RUN ln -s /etc/nginx/sites-available/adminer.conf /etc/nginx/sites-enabled/
# RUN ln -s /etc/nginx/sites-available/subdomain.conf /etc/nginx/sites-enabled/

ENTRYPOINT [ "nginx", "-g", "daemon off;" ]