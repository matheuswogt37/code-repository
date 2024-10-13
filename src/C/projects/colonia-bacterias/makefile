LIB_FLAGS=-pthread -lm
OUTPUT_FILE=growth_simulation
PARAMS=-pi 10 -r 2 -t 5 -nc 5 -nr 1
.PHONY: test clear run

test: clear compile run clean
testTime: clear compile timeRun clean

clear:
	@clear

compile: ${OUTPUT_FILE}.c
	@gcc -o ${OUTPUT_FILE} ${OUTPUT_FILE}.c ${LIB_FLAGS}

run: ${OUTPUT_FILE}
	./${OUTPUT_FILE} ${PARAMS}

timeRun: ${OUTPUT_FILE}
	@time ./${OUTPUT_FILE} ${PARAMS}

clean: ${OUTPUT_FILE}
	@rm ./${OUTPUT_FILE}