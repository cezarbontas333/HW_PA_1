# Recipies:
# make build	# Builds all the source files directly into a binary. Default option.
# make debug	# Same as the above, but it adds additional flags to be added
#				# when Valgrind is used later.
# make clean	# Deletes the binary.
# Since the scope of this project is small, there is no need to create a recipe for
# each file for separate compilation.

COMPILER := gcc
SRCS := main.c task1.c task2.c task3.c
BIN := lanParty
DEBUGFLAG := -ggdb3
ARGS := c.in d.in r.out

build: ${SRCS}
	@echo "Building release version."
	${COMPILER} ${SRCS} -o ${BIN}

debug: ${SRCS}
	@echo "Building debug version."
	${COMPILER} ${SRCS} -o ${BIN}_debug ${DEBUGFLAG}
	@echo "Executing Valgrind..."
	@valgrind -s ./lanParty_debug ${ARGS}

clean:
	@echo "Cleaning all files!"
	rm -rf ${BIN} ${BIN}_debug