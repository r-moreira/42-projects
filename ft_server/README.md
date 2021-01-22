# FT_SERVER

## Docker CLI
* docker build -t [image-name:tag] .

* docker run [flags] [image-name]
	* FLAGS:
		* -it -> iterative mode
		* -d  -> detach mode
		* --name [container-name] -> set container-name
		* -p [port:port] -> link localhost and container ports

* docker stop [container-name] -> to stop a running container

* docker exec -it [container-name] bash -> to enter in a container

* docker rm [container-name] -> to remove a container

* docker image rm [image-name] -> to remove a image

* docker ps -> to list active containers
* docker ps -a -> to list all containers

* docker images ls -> to list images

* docker container prune -> to remove all stoped containers

* docker system prune -> to remove all images
