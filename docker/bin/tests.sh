set -e
source `dirname $0`/env.sh

echo
echo "Running tests."
echo

${SCRIPT_DIR}/start.sh

${COMPOSE} exec python sh -c "cd /home/hovertaxi-build/cmake-build-debug && make hovertaxi_test && ./hovertaxi_test"





