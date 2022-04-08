CC = gcc
CFLAGS = -W -Wall
TARGET = main.out
TEST_TARGET = test.out
SRC = $(wildcard src/*/*.c)
OBJECTS = $(patsubst %.c,%.o,$(subst src,build/src,$(SRC)))
MAIN_OBJECTS = $(filter build/src/main/%.o, $(OBJECTS))
TEST_OBJECTS = $(filter build/src/test/%.o, $(OBJECTS))
TESTS = $(patsubst %Test.o,%.o,$(subst src/test,src/main,$(TEST_OBJECTS)))
STUDY_SRC = $(notdir $(filter src/study/%.c, $(SRC)))
STUDY_OUT = $(STUDY_SRC:.c=.c.out)
UNITY_PATH = src/test/unity/src
UNITY = build/$(UNITY_PATH)/unity.o


build/src/*/%.o : src/*/%.c
	@$(CC) $(CFLAGS) -c -o $@ $^
	@echo compiled $^


all : compile blank run


compile : start $(TARGET) $(TEST_TARGET) end test


main : start $(TARGET) end run


study :
	@for src in $(STUDY_SRC) ; do \
		$(CC) -o $$src.out src/study/$$src ; \
		echo maked $$src.out ; \
	done
	@echo
	@make studyR


studyR :
	@for out in $(STUDY_OUT) ; do \
		echo run $$out ; \
		echo ----------------------------------------- ; \
		./$$out ; \
		echo ; \
		echo ; \
		echo ----------------------------------------- ; \
		echo complete $$out ; \
		echo ; \
	done


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


$(TARGET) : $(MAIN_OBJECTS)
	@$(CC) -o $@ $^
	@echo maked $@


$(TEST_TARGET) : $(TEST_OBJECTS)
	@$(CC) -o $@ $^ $(TESTS) $(UNITY)
	@echo maked $@


build :
	@echo build start ...
	@mkdir -p src/{main,study,test}
	@mkdir -p build/src/{main,test} build/$(UNITY_PATH)
	@echo maked build directory .
	@$(CC) -c -o $(UNITY) $(UNITY_PATH)/unity.c
	@echo maked unity object file .
	@echo
	-@make all
	@echo
	@echo build complete !


buildM :
	@echo build start ...
	@mkdir -p src/{main,study}
	@echo maked src direcotry .
	@mkdir -p build/src/main
	@echo maked build directory .
	@echo
	-@make main
	@echo
	@echo build complete !


clean :
	@rm -rf build/ *.out src/*/*.o
	@echo deleted object and run files .

