FILE="main.c"
PARAMS="./"
.PHONY: test clear

test: clear compile run clean

clear:
	@clear

compile: $(FILE)
	@echo compilando $(FILE).out
	@gcc $(FILE) -o $(FILE).out

run: $(FILE).out
	@./$(FILE).out $(PARAMS)

clean: $(FILE).out
	@rm $(FILE).out