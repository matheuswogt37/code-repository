LIB_FLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi
.PHONY: test clear run clean


test: clear compile run clean

clear:
	@clear

compile: main.cpp
	@g++ main.cpp -o main.o ${LIB_FLAGS}
	
run: compile
	@./main.o

clean:
	@rm -r ./*.o