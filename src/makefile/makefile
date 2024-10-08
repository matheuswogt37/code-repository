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