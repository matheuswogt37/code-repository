LIB_FLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi
.PHONY: run clean test


test: compile run clean

compile: main.cpp
	g++ main.cpp -o main.o ${LIB_FLAGS}
	
run: compile
	./main.o

clean:
	rm -r ./*.o