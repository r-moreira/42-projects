HOST = user42

all:
	mkdir /home/$(HOST)/data/;\
	mkdir /home/$(HOST)/data/mysql/;\
	mkdir /home/$(HOST)/data/wordpress/;\
	sudo chmod -R 777 /home/$(HOST)/data;\
	docker-compose -f ./srcs/docker-compose.yml up -d --build

down:
	docker-compose -f ./srcs/docker-compose.yml down

clean:
	docker stop $$(docker ps -qa);\
	docker rm $$(docker ps -qa);\
	docker rmi -f $$(docker images -qa);\
	docker volume rm $$(docker volume ls -q);\
	docker network rm $$(docker network ls -q);\
	sudo rm -rf /home/$(HOST)/data

.PHONY: all re down clean