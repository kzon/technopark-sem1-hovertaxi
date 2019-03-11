source `dirname $0`/env.sh

${COMPOSE} logs -f $1
