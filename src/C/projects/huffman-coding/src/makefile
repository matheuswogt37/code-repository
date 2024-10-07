SRC_FILE=files/
.PHONY: clear test run remove 


test: clear build run remove $(SRC_FILE)

clear:
	@clear

build: 
	@gcc main.c -o output.o

run: build ${SRC_FILE}
	@./output.o ${SRC_FILE}

remove: build
	@rm ./output.o