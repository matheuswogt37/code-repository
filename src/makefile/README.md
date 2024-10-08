# Makefile
Makefile are used to help compile C/C++, i use to compile and make other stuffs more faster, just typing "make" instead "clear && gcc main.c -o main.out ......"

## How I use?
Let's take an example;

```makefile
LIB_FLAGS = -pthread -lm
FILE="main.c"
.PHONY: test clear

test: clear compile run clean

clear:
	@clear

compile: $(FILE)
	@echo compilando $(FILE).out
	@gcc $(FILE) -o $(FILE).out $(LIB_FLAGS)

run: $(FILE).out
	@./$(FILE).out

clean: $(FILE).out
	@rm $(FILE).out
```

the first line is a variable
```makefile
LIB_FLAGS = -pthread -lm
```

the second is a variable used as parameter and your default value, so when i call the makefile using "make" only the FILE will had the value "main.c" but i can assign when call using "make FILE=funct.c" and the FILE value will be funct.c
```makefile
FILE="main.c"
```

the third is used to declare who will not use files, let's check the 'compile' who require a file to execute his instructions, but 'clear' not require, so 'clear' is defined in .PHONY to not require a file to execute properly
```makefile
.PHONY: test clear
```

the others are let's call "functions", by default they need a file that is defined after the function name and two dots, like
```makefile
compile: file.c
```
this "function" called compile need a file named 'file.c' to execute, this can be used to call other functinos too, like:
```makefile
test: clear compile run clean
```
this will call all the "functions" required in order before the 'test' be executed, even something is required this need be in .PHONY because there is no file in the requirements

in a "function" can call commands like echo, ls, rm, touch, etc. and when used show the line and the output of this same line, example:
```makefile
echo hello world
```
output will be:
```makefile
echo hello world
hello world
```
the output is the command line and the effect of command line, to print only the effect we use '@' before the command line, like:
```makefile
@echo hello world
```
the output is:
```makefile
hello world
```