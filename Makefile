CC = gcc
CFLAGS = -W -Wall
MK = make --no-print-directory
INCLUDE = -Iincludes -I$(UNITY_SRC_PATH) -I$(UNITY_EXTRAS_PATH)
TARGET = main.out
TEST_TARGET = test.out
SRC = $(wildcard src/*/*.c) $(wildcard src/*/*/*.c)
OBJECTS = $(patsubst %.c,%.o,$(subst src,build/src,$(SRC)))
MAIN_OBJECTS = $(filter build/src/main/%.o, $(OBJECTS))
TEST_OBJECTS = $(filter build/src/test/%.o, $(OBJECTS))
TESTS = $(filter-out build/src/main/main.o, $(MAIN_OBJECTS))
STUDY_SRC = $(notdir $(filter src/study/%.c, $(SRC)))
STUDY_OUT = $(STUDY_SRC:.c=.c.out)
UNITY_PATH = src/test/unity
UNITY_SRC_PATH = $(UNITY_PATH)/src
UNITY_EXTRAS_PATH = $(UNITY_PATH)/extras/src
UNITY = build/$(UNITY_SRC_PATH)/unity.o
UNITY_EXTRAS = build/$(UNITY_EXTRAS_PATH)/*.o
UNITY_OBJECTS = $(UNITY) $(UNITY_EXTRAS)


build/src/main/%.o : src/main/%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^
	@echo compiled $^


build/src/test/%.o : src/test/%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^
	@echo compiled $^


%.c.out : src/study/%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -o $@ $^
	@echo maked $@


all : compile blank run


compile :
	@echo compile start ...
	@echo -----------------------------------------
	@$(MK) $(TARGET)
ifneq ($(TEST_OBJECTS),)
	@$(MK) test
endif
	@echo
	@echo -----------------------------------------
	@echo compile complete !


study : $(STUDY_OUT)
	@for out in $(STUDY_OUT) ; do \
		echo ; \
		echo run $$out ; \
		echo ----------------------------------------- ; \
		./$$out ; \
	done


blank :
	@echo


run :
	@echo run $(TARGET)
	@echo -----------------------------------------
	@-./$(TARGET)


test : $(TEST_TARGET)
	@echo
	@echo test start ...
	@echo -----------------------
	@./test.out
	@echo test complete !


$(TARGET) : $(MAIN_OBJECTS)
	@$(CC) -o $@ $^
	@echo maked $@


$(TEST_TARGET) : $(TEST_OBJECTS)
	@$(CC) -o $@ $^ $(TESTS) $(UNITY_OBJECTS)
	@echo maked $@


init :
	@echo init ...
	@$(MK) clean
	@mkdir -p src/main src/test src/study $(UNITY_SRC_PATH) $(UNITY_EXTRAS_PATH) includes
	@echo maked src directory .
	@echo unity download start ...
	-@git clone https://github.com/ThrowTheSwitch/Unity.git
	@cp Unity/src/* $(UNITY_SRC_PATH)
	@cp Unity/extras/fixture/src/* $(UNITY_EXTRAS_PATH)
	@cp Unity/extras/memory/src/* $(UNITY_EXTRAS_PATH)
	@rm -rf Unity
	@echo unity download complete !
	@echo
	@$(MK) build
	@echo done .


initM :
	@echo init ...
	@$(MK) clean
	@mkdir -p src/main src/study includes
	@echo maked src direcotry .
	@echo
	@$(MK) build
	@echo done .


build :
	@echo build start ...
	@mkdir -p build/src/main
ifneq ($(wildcard $(UNITY_SRC_PATH)/unity.c),)
	@mkdir -p build/src/test build/$(UNITY_SRC_PATH) build/$(UNITY_EXTRAS_PATH)
	@echo maked build directory .
	@$(CC) -c -o $(UNITY) $(UNITY_SRC_PATH)/unity.c
	@$(CC) -I$(UNITY_SRC_PATH) -c -o build/$(UNITY_EXTRAS_PATH)/unity_fixture.o $(UNITY_EXTRAS_PATH)/unity_fixture.c
	@$(CC) -I$(UNITY_SRC_PATH) -c -o build/$(UNITY_EXTRAS_PATH)/unity_memory.o $(UNITY_EXTRAS_PATH)/unity_memory.c
	@echo maked unity object file .
else
	@echo maked build directory .
endif
	@echo
	-@$(MK) all
	@echo
	@echo build complete !


clean :
	@rm -rf build/ *.out src/*/*.o
	@echo deleted object and run files .
