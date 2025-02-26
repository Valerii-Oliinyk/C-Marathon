#!/bin/bash

gcc -Wall -Wextra -Werror -c *.c

ar rcs minilibmx.a *.o

rm -f *.o