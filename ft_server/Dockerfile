FROM debian:buster

RUN apt-get -y update

RUN apt-get install -y \
	nginx \
	php-fpm \
	php-mysql \
	php-mbstring


# Copy scripts from src directory to the container's temp directory.
COPY srcs /tmp/

EXPOSE 80

# Start services
ENTRYPOINT bash /tmp/setup.sh
