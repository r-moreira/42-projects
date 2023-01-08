# Setup

1) Add to /etc/hosts
romoreir.42.fr

# Test

## Wordpress Page
https://https://romoreir.42.fr

## Wordpress Admin
https://romoreir.42.fr/wp-admin/

## Mariadb Databse
docker-compose exec mariadb bash

mysql -uroot

mysql -uroot -p

mysql -u romoreir -p 

SELECT host, user, password, plugin FROM mysql.user;
 
SHOW DATABASES;
use 'wordpress';
SHOW TABLES;
SELECT wp_users.display_name FROM wp_users;
SELECT *  FROM wp_users;

# Comando para desabilitar login sem senha no root
UPDATE mysql.user SET plugin = 'mysql_native_password' WHERE user = 'root'; FLUSH PRIVILEGES;

# Dump do SQL
mysqldump -u root -p --all-databases > dump.sql
sudo docker cp mariadb:/dump.sql ~/Dev/

# rootPassword
# userPassword
# guestPassword