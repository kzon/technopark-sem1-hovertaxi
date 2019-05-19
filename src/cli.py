import sys

import models
from extern import order

if len(sys.argv) < 2:
    print('Expected command name')
    exit()

command = sys.argv[1]
extern_wrapper = order.get_wrapper(models.Context(''))
if command == 'process_orders':
    orders_processed = extern_wrapper.process_orders()
    print(orders_processed)
