CC = gcc
CFLAGS = -W -Wall
TARGET = main.out
TEST_TARGET = test.out
SRC = $(wildcard src/main/*.c)
OBJECTS = $(patsubst %.c,%.o,$(subst src,build/src,$(SRC)))
TEST_SRC = $(wildcard src/test/*.c)
TEST_OBJECTS = $(patsubst %.c,%.o,$(subst src,build/src,$(TEST_SRC)))
TESTS = $(patsubst %Test.o,%.o,$(subst src/test,src/main,$(TEST_OBJECTS)))
UNITY_PATH = src/test/unity/src
UNITY = build/$(UNITY_PATH)/unity.o


build/src/*/%.o : src/*/%.c
	@$(CC) $(CFLAGS) -c -o $@ $^
	@echo compiled $^


all : compile blank run


compile : start $(TARGET) $(TEST_TARGET) end test


main : start $(TARGET) end run


start :
	@echo compile start ...
	@echo -----------------------------------------


blank :
	@echo


end :
	@echo
	@echo -----------------------------------------
	@echo compile complete !
	@echo


run :
	@echo run $(TARGET)
	@echo -----------------------------------------
	@-./$(TARGET)


test :
	@echo test start ...
	@echo -----------------------
	@./test.out
	@echo test complete !


$(TARGET) : $(OBJECTS)
	@$(CC) -o $@ $^
	@echo maked $@


$(TEST_TARGET) : $(TEST_OBJECTS)
	@$(CC) -o $@ $^ $(TESTS) $(UNITY)
	@echo maked $@


build :
	@echo build start ...
	@mkdir -p build/src/{main,test} build/$(UNITY_PATH)
	@echo maked build file .
	@$(CC) -c -o $(UNITY) $(UNITY_PATH)/unity.c
	@echo maked unity object file .
	@echo
	@make all
	@echo
	@echo build complete !


buildM :
	@echo build start ...
	@mkdir -p build/src/main
	@echo maked build file .
	@echo
	@make main
	@echo
	@echo build complete !


clean :
	@rm -rf build/ *.out src/*/*.o
	@echo deleted object and run files .

