CC = gcc
CFLAGS = -W -Wall
TARGET = main.out
TEST_TARGET = test.out
SRC = $(wildcard src/main/*.c)
OBJECTS = $(SRC:src/main/%.c=build/src/main/%.o)
TEST_SRC = $(wildcard src/test/*.c)
TEST_OBJECTS = $(TEST_SRC:src/test/%.c=build/src/test/%.o)
TESTS = $(TEST_OBJECTS:build/src/test/%Test.o=build/src/main/%.o)
UNITY_PATH = src/test/unity/src
UNITY = build/$(UNITY_PATH)/unity.o
BLANK = $(shell echo)


build/src/*/%.o : src/*/%.c
	@$(CC) $(CFLAGS) -c -o $@ $^
	@echo compiled $^


all : compile run


compile : start $(TARGET) $(TEST_TARGET) end blank test


compileM : start $(TARGET) end blank run


start :
	@echo compile start ...
	@echo -----------------------------------------


blank :
	@echo


end :
	@echo
	@echo -----------------------------------------
	@echo compile complete !


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
	@make compileM
	@echo
	@echo build complete !


clean :
	@rm -rf build/ *.out src/*/*.o
	@echo deleted object and run files .

