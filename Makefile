CC = gcc
CFLAGS = -Wall -Werror -std=c11

SRC_MAIN = main.c
OBJ_MAIN = $(SRC_MAIN:.c=.o)

.PHONY: all clean test

all: main_program mfoo

main_program: $(OBJ_MAIN) $(OBJ_FOO)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f main_program mfoo $(OBJ_MAIN) $(OBJ_FOO) $(OBJ_TEST) $(TEST_RESULTS)

# UNIT TESTS

SRC_FOO = ADT/Foo/foo.c
SRC_TEST = ADT/Foo/tests/mfoo.c
OBJ_FOO = $(SRC_FOO:.c=.o)
OBJ_TEST = $(SRC_TEST:.c=.o)

TESTS_DIR = ADT/Foo/tests
TEST_CASES = $(wildcard $(TESTS_DIR)/*.in)
TEST_OUTPUTS = $(TEST_CASES:.in=.out)
TEST_RESULTS = $(TEST_CASES:.in=.result)

mfoo: $(OBJ_FOO) $(OBJ_TEST)
	$(CC) $(CFLAGS) -o $@ $^

test_foo: mfoo $(TEST_RESULTS)
	@cat $(TEST_RESULTS)

$(TEST_RESULTS): $(TESTS_DIR)/%.result: $(TESTS_DIR)/%.in $(TESTS_DIR)/%.out mfoo
	@if ./mfoo < $< | diff - $(word 2,$^) > /dev/null; then \
		echo "$< $(word 2,$^): TRUE"; \
	else \
		echo "$< $(word 2,$^): WRONG"; \
	fi > $@

# UNIT TEST Wordmachine

SRC_LIB = $(SRC_CHAR) $(SRC_WORD) $(SRC_PCOLOR)
OBJ_LIB = $(SRC_LIB:.c=.o)

SRC_AWAS = $(SRC_KICAUAN) $(SRC_DRAFT)

SRC_CHAR = ADT/Wordmachine/charmachine.c
SRC_WORD = ADT/Wordmachine/wordmachine.c
SRC_KICAUAN = ADT/Kicauan/kicauan.c
SRC_DRAFT = ADT/Draftkicauan/draftkicauan.c

SRC_PCOLOR = ADT/pcolor/pcolor.c

OBJ_CHAR = $(SRC_CHAR:.c=.o)
OBJ_WORD = $(SRC_WORD:.c=.o)


wordmachine: $(OBJ_CHAR) $(OBJ_WORD)
	$(CC) $(CFLAGS) -o $@ $^ 


edbert: $(OBJ_LIB) util.c main.c globalVar.h globalVar.c $(SRC_AWAS)
	$(CC) $(CFLAGS) -o $@  main.c globalVar.c $(SRC_LIB)