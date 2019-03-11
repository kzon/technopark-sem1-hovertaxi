set -e
source `dirname $0`/env.sh

echo
echo "Initializing virtual services with $DOCKER_FILE"
echo

echo + creating services
${COMPOSE} up -d --build --remove-orphans

echo + check running services
${COMPOSE} ps
