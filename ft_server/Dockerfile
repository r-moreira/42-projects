FROM debian:buster

LABEL maintainer="romoreir romoreir@student.42.sp"

## Updates OS
RUN apt-get -y update && apt-get upgrade

## Install dependencies
RUN apt-get install -y \
	nginx \
	php-fpm \
	php-mysql \
	php-mbstring \
	mariadb-server \
	openssl \
	wget

## Install PHPMyAdmin
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-english.tar.gz && \
	tar -xzvf phpMyAdmin-5.0.4-english.tar.gz && \
	mv phpMyAdmin-5.0.4-english/ /var/www/html/phpmyadmin && \
	rm -rf phpMyAdmin-5.0.4-english.tar.gz

# Install WordPress
RUN wget https://wordpress.org/latest.tar.gz && \
	tar -xzvf latest.tar.gz && \
	mv wordpress /var/www/html/ && \
	rm -rf latest.tar.gz

# Copying srcs folder files to the container's temporary directory
COPY srcs/ /tmp/

# Giving permissions to the setup script
RUN chmod 777 /tmp/setup.sh

# Ports that will be used to access the server
EXPOSE 80 443

# This variable choses wich nginx configuration file that will be used
ENV AUTOINDEX=0N

# Start services
ENTRYPOINT /tmp/setup.sh
