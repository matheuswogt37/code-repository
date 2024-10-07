LIB_FLAGS = -g $(find . -type f -iregex ".*\.c")
.PHONY: test build clear run remove


test: build remove
build: clear compile run

clear:
	@clear

compile: main.c
	@gcc main.c -o main ${LIB_FLAGS}

run:
	@./main

remove:
	@rm ./main