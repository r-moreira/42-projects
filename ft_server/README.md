## 🚀 FT_SERVER
The goal of ft_server is to create a web server with Nginx capable of running a WordPress website, phpMyAdmin, and a MySQL database.

This server will run in only one Docker container, under Debian Buster and also have a self-signed certificate  and an autoindex script on the container's root directory.

* Web server with [Nginx](https://www.nginx.com/)
* SQL Database with [MariaDB](https://www.mariadb.org/)
* Database web admin with [PhpMyAdmin](https://www.phpmyadmin.net/)
* OpenSource CMS with [Wordpress](https://www.wordpress.com/)
* Selg-Signed Certificate with [OpenSSL](https://www.openssl.org/)

---

## 📖 Subject
There is a PDF in the subject folder containing details about the project.


 --------

## 🖥️ Running
`git clone https://github.com/r-moreira/42-projects.git` => clone the repository\
`cd get_next_line/` => go to the project folder\
`docker build -t $(IMAGE_NAME) .` => builds the image\
`docker run -it -p 80:80 -p 443:443 --name $(CONTAINER_NAME) $(IMAGE_NAME)` => runs the image as a container\
`docker stop $(CONTAINER_NAME)` => stops the container\
`docker rmi $(IMAGE_NAME)` => removes the image\
`docker rm $(CONTAINER_NAME)` => removes the container\

--------

## ✅ Web Server endpoints:

- <https://localhost>
- <https://localhost/wordpress>
- <https://localhost/phpmyadmin>