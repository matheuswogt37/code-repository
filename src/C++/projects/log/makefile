LIB_FLAGS = -pthread
.PHONY: test log clear

test: clear compile run clean

log: clear compile runLog clean

clear:
	@clear

compile: main.cpp
	@g++ -g $$(find . -type f -iregex ".*\.cpp") -o main.out ${LIB_FLAGS}

run: main.out
	@time ./main.out

runLog: main.out
	@time ./main.out > log.txt

clean: main.out
	@rm ./main.out