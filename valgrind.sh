#!/bin/bash
valgrind -v --tool=memcheck --leak-check=full --log-file=valgrind.log --show-leak-kinds=all ./msgpack_0.5.7-bug-1469090-reproduce
