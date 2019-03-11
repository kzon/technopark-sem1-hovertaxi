SCRIPT_DIR=`dirname $0`
PROJECT_NAME=hovertaxi
DOCKER_FILE="${SCRIPT_DIR}/../docker-compose.yml"
COMPOSE="docker-compose -p ${PROJECT_NAME} -f ${DOCKER_FILE}"
