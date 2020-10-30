
SHELL := /bin/bash

.PHONY: all test clean

all:
	source cmd.sh && compiling

single-%:
	source cmd.sh && compiling $(patsubst single-%, %, $@)

test:
	source cmd.sh && testing

clean:
	source cmd.sh && cleaning
