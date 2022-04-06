CC = gcc
CFLAGS = -W -Wall
TARGET = main.out
TEST_TARGET = test.out
SRC = $(wildcard src/main/*.c)
OBJECTS = $(SRC:.c=.o)
BUILD_OBJS = $(wildcard build/src/main/*.o)
TEST_SRC = $(wildcard src/test/*.c)
TEST_OBJECTS = $(TEST_SRC:.c=.o)
TEST_BUILD_OBJS = $(wildcard build/src/test/*.o)
TESTS = $(TEST_OBJECTS:src/test/%Test.o=build/src/main/%.o)
UNITY_PATH = src/test/unity/src
UNITY = build/$(UNITY_PATH)/unity.o


%.o : %.c
	@$(CC) $(CFLAGS) -c -o build/$@ $^
	@echo compiled $^


all : compile test
	@rm -f src/*/*.o
	@echo
	@echo deleted trash files .


compile : start copy $(TARGET)
	@echo compile complete of main !


start :
	@echo compile start ...


copy :
	@echo copy object files ...
	@rsync -azh build/src . --exclude=build/src/test/unity


$(TARGET) : $(OBJECTS)
	@$(CC) -o $@ $(BUILD_OBJS)
	@echo maked $@


test : $(TEST_TARGET)
	@echo compile complete of test !
	@echo
	@echo test start ...
	@echo
	@./test.out
	@echo test complete !


$(TEST_TARGET) : $(TEST_OBJECTS)
	@$(CC) -o $@ $(TEST_BUILD_OBJS) $(TESTS) $(UNITY)
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
	@mkdir -p build/src/{main,test} build/$(UNITY_PATH)
	@echo maked build file .
	@echo
	@make compile	
	@rm -f src/*/*.o
	@echo
	@echo deleted trash files .
	@echo
	@echo build complete !


clean :
	@rm -rf build/ *.out
	@echo deleted build and run files .

