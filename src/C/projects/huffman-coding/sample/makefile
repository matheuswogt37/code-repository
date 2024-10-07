DEFAULT_FILE_TEST = ./files/sample
.PHONY: clear test run remove 

test: clear build run remove

clear:
	@clear

build: 
	@gcc main.c -o output.o

run: 

	@if [ -z "$(fName)" ]; then \
		./output.o $(DEFAULT_FILE_TEST) ; \
		echo '\nparam default\n' ; \
	else \
		./output.o $(fName) ; \
		echo '\nparam - $(fName)\n' ; \
	fi
	
remove: 
	@rm ./output.o