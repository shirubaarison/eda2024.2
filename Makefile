CC = gcc
CFLAGS = -Wall
COMMON = src/common.c

SRC_DIR = src

TARGET = hash
TEST = hash_test

clean:
	rm -f $(OBJ) $(TARGET)

dobra:
	$(CC) src/dobra.c playground/hash_dobra.c ${CFLAGS} $(COMMON) -o ${TARGET}

div:
	$(CC) src/div.c playground/hash_div.c ${CFLAGS} $(COMMON) -o ${TARGET}

test: 
	$(CC) tests/hash_test.c $(SRC_DIR)/dobra.c $(SRC_DIR)/div.c ${CFLAGS} $(COMMON) -o ${TEST}
	./${TEST}