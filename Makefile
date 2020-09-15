
SHELL := /bin/bash

.PHONY: all test clean

all:
	source cmd.sh && compiling

test:
	source cmd.sh && testing

clean:
	source cmd.sh && cleaning
