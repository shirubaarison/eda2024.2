CC = gcc
CFLAGS = -Wall -lm
COMMON = src/common.c

HASH_DIR = src/hash
AVL_DIR = src/avl
SRC_DIR = src
TEST_DIR = tests

TARGET = hash
TEST = hash_test
TEST_AVL = avl_test

clean:
	rm -f $(TARGET) $(TEST)

dobra:
	$(CC) ${HASH_DIR}/dobra.c playground/hash_dobra.c ${CFLAGS} $(COMMON) -o ${TARGET}

div:
	$(CC) ${HASH_DIR}/div.c playground/hash_div.c ${CFLAGS} $(COMMON) -o ${TARGET}

mult:
	$(CC) ${HASH_DIR}/multiplicacao.c ${CFLAGS} $(COMMON) -o ${TARGET}

test: 
	$(CC) tests/hash_test.c ${HASH_DIR}/dobra.c ${HASH_DIR}/mult.c ${HASH_DIR}/div.c ${CFLAGS} $(COMMON) -o ${TEST}
	./${TEST}

test_dobra:
	$(CC) tests/hash_dobra_test.c ${HASH_DIR}/dobra.c  ${TEST_DIR}/test_helper.c ${CFLAGS} $(COMMON) -o ${TEST}
	./${TEST}

test_div:
	$(CC) tests/hash_div_test.c ${HASH_DIR}/div.c  ${TEST_DIR}/test_helper.c ${CFLAGS} $(COMMON) -o ${TEST}
	./${TEST}

avl-test:
	$(CC) ${AVL_DIR}/avl.c tests/avl_test.c ${CFLAGS} $(COMMON) -o ${TEST_AVL}
	./${TEST_AVL}