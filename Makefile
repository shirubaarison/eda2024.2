CC = gcc
CFLAGS = -Wall
OBJECTS = fold.o hash.o common.o
COMMON = include/common.c

TARGET = hash

clean:
	rm -f $(OBJ) $(TARGET)

dobra:
	$(CC) src/dobra.c ${CFLAGS} $(COMMON) -o ${TARGET}

div:
	$(CC) src/div.c ${CFLAGS} $(COMMON) -o ${TARGET}