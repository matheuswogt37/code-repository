C_FILE?=makefile.error.c
.PHONY: clear test run remove 


test: clear build run remove

clear:
	@clear

build: $(C_FILE) 
	@gcc $(C_FILE) -o output.o

run: build
	@./output.o

remove: build
	@rm ./output.o