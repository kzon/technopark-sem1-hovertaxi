set -e
source `dirname $0`/env.sh

echo
echo "Running tests."
echo

${SCRIPT_DIR}/start.sh

${SCRIPT_DIR}/logs.sh

${COMPOSE} exec python sh -c "cd /home/hovertaxi-build/cmake-build-debug && make hovertaxi_test && ./hovertaxi_test"





