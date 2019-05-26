import sys
import tasks

if len(sys.argv) < 2:
    print('Expected command name')
    exit()

command = sys.argv[1]
if command == 'process_orders':
    print(tasks.process_orders())
