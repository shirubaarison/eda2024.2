CC = gcc
CFLAGS = -Wall
COMMON = src/common.c

HASH_DIR = src/hash
SRC_DIR = src

TARGET = hash
TEST = hash_test

clean:
	rm -f $(TARGET) $(TEST)

dobra:
	$(CC) ${HASH_DIR}/dobra.c playground/hash_dobra.c ${CFLAGS} $(COMMON) -o ${TARGET}

div:
	$(CC) ${HASH_DIR}/div.c playground/hash_div.c ${CFLAGS} $(COMMON) -o ${TARGET}

test: 
	$(CC) tests/hash_test.c ${HASH_DIR}/dobra.c ${HASH_DIR}/div.c ${CFLAGS} $(COMMON) -o ${TEST}
	./${TEST}