TARGET := Assembler
CC := gcc
RM := /bin/rm
OBJECTS := Parser.o Code.o main.o
CFLAGS := -Wall -g

all: ${TARGET}

${TARGET}: ${OBJECTS}
	${CC} -o Assembler ${OBJECTS}

Parser.o : Parser.c Parser.h
	${CC} -c Parser.c ${CFLAGS}

Code.o: Code.c
	${CC} -c Code.c  ${CFLAGS}

main.o: main.c Parser.h
	${CC} -c main.c  ${CFLAGS}

clean:
	${RM} -rf ${TARGET} ${OBJECTS}
