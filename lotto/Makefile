CC = gcc
CFLAGS = -W -Wall
TARGET = main.out
TEST_TARGET = test.out
SRC = $(wildcard src/main/*.c)
OBJECTS = $(SRC:.c=.o)
TEST_SRC = $(wildcard src/test/*.c)
TEST_OBJECTS = $(TEST_SRC:.c=.o)
TESTS = $(TEST_OBJECTS:src/test/%Test.o=build/src/main/%.o)
UNITY_PATH = src/test/unity/src
UNITY = build/$(UNITY_PATH)/unity.o


%.o : %.c
	@$(CC) $(CFLAGS) -c -o build/$@ $^
	@echo compiled $^


all : compile blank run


compile : start copy $(TARGET) blank $(TEST_TARGET) blank delete blank test


compileM : start copy $(TARGET) blank delete blank run


compileT : start copy $(TEST_TARGET) blank delete blank test


start :
	@echo compile start ...


copy :
	@echo copy object files ...
	@rsync -azvh --exclude 'test/unity' build/src .


blank :
	@echo


delete :
	@echo compile complete !
	@rm -f src/*/*.o
	@echo deleted trash files .


run :
	@echo run $(TARGET)
	@-./$(TARGET)


test :
	@echo test start ...
	@echo
	@./test.out
	@echo test complete !


$(TARGET) : $(OBJECTS)
	@$(CC) -o $@ $(wildcard build/src/main/*.o)
	@echo maked $@


$(TEST_TARGET) : $(TEST_OBJECTS)
	@$(CC) -o $@ $(wildcard build/src/test/*.o) $(TESTS) $(UNITY)
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

