LIB_THREAD = -lpthread
.PHONY: test clear run

test: clear compile run

clear:
	@clear

compile: selvagens2.c
	@gcc selvagens2.c -o main.out ${LIB_THREAD}

run:
	@./main.out
	@echo