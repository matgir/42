FROM debian:bullseye

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install -y nginx openssl
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt -subj '/C=FR/ST=Ile-de-France/L=Paris/O=42/OU=42Paris/CN=MGIRARDO/UID=TTT'
	# creates the certificate	req : create certificate signing request
								# 	-x509 : selfsigned certificate
								# 	-nodes : whithout mdp for the private key
								# 	-newkey : creates new key with certificate, size 2048
								# 	-out : where to put the certificate
								# 	-keyout : where to put the key
								# 	/field=value : specifies information about certificate

RUN openssl dhparam -out /etc/nginx/dhparam.pem 2048
# creates the file that will be used for the enryption in Diffie-Hellman key exchange

COPY ./conf/ssl-params.conf /etc/nginx/snippets/

COPY ./conf/default /etc/nginx/sites-available/

ENTRYPOINT [ "nginx", "-g", "daemon off;" ]