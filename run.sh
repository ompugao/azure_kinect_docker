#!/bin/bash
CONTAINER=${1:-app}
set -e

#XAUTH=/tmp/.docker.xauth
#DISPLAY=:1
source .env
rm $XAUTH
touch $XAUTH
xauth nlist $DISPLAY | sed -e 's/^..../ffff/' | xauth -f $XAUTH nmerge -
chmod a+r $XAUTH
xhost +local:

docker-compose -f ./docker-compose.yml up -d
set +e
docker-compose exec ${CONTAINER} bash



