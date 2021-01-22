#!/bin/bash

# Setup PHP file to localhost folder for tests.
mv /tmp/index.php /var/www/html/index.php

# Setup NGINX config file.
mv /tmp/nginx.conf /etc/nginx/sites-available/default

# Start services
service nginx start
service php7.3-fpm start

# Keeps container running
tail -f /dev/null
