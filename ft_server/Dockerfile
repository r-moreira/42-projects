FROM debian:buster

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

COPY srcs/ /tmp/

EXPOSE 80

# Start services
ENTRYPOINT bash /tmp/setup.sh
