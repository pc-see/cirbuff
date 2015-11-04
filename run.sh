#!/bin/bash
echo "\nTesting enqueue"
make test-enqueue > /dev/null && ./test-enqueue && rm test-enqueue
echo "\nTesting dequeue"
make test-dequeue > /dev/null && ./test-dequeue && rm test-dequeue
