LIB_THREAD = -lpthread
.PHONY: test clear clean

test: clear compile run_log cat_log clean

clear:
	@clear

compile: semaphore.c
	@gcc semaphore.c -o main.out ${LIB_THREAD}

run_log: main.out
	@./main.out > log.txt

cat_log: log.txt
	@cat log.txt

clean:
	@rm ./main.out