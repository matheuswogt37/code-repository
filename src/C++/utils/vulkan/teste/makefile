LIB_FLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

test: main.cpp
	g++ main.cpp -o main ${LIB_FLAGS}
	./main
	rm ./main