#!/bin/bash

# Setup PHPMyAdmin config file;
mv /tmp/config.inc.php /var/www/html/phpmyadmin/

# Setup WordPress config file.
mv /tmp/wp-config.php /var/www/html/wordpress

# Setup NGINX config file.
mv /tmp/nginx.conf /etc/nginx/sites-available/default
# Giving NGINX's user-group rights over page files
chown -R www-data:www-data /var/www/html/*
# Removing nginx html view
rm var/www/html/index.nginx-debian.html


# Start services
service mysql start
service php7.3-fpm start
service nginx start

# Setup DataBase
echo "CREATE DATABASE IF NOT EXISTS wordpress;" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost';" | mysql -u root --skip-password
echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password
echo "update mysql.user set plugin = 'mysql_native_password' where user='root';" | mysql -u root

# Keeps container running
tail -f /dev/null
