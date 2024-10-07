LIB_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lGL
.PHONY: clear test run clean


test: clear compile run clean

compile: main.cpp
	@g++ -g $$(find . -type f -iregex ".*\.cpp") -o main.o ${LIB_FLAGS}

run: compile
	@./main.o

clean:
	@rm -r ./*.o

clear:
	@clear