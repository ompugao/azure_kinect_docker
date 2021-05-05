#!/bin/bash
CONTAINER=${1:-app}
set -e

XAUTH=/tmp/.docker.xauth
touch $XAUTH
xauth nlist :0 | sed -e 's/^..../ffff/' | xauth -f $XAUTH nmerge -
chmod a+r $XAUTH

docker-compose -f ./docker-compose.yml up -d
set +e
docker-compose exec ${CONTAINER} bash



