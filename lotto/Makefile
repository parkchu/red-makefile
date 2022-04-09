CC = gcc
CFLAGS = -W -Wall
INCLUDE = $(subst src,-Isrc,$(HEADER_PATH)) -I$(UNITY_SRC_PATH) -I$(UNITY_EXTRAS_PATH)
TARGET = main.out
TEST_TARGET = test.out
SRC = $(wildcard src/*/*.c) $(wildcard src/*/*/*.c)
HEADER = $(wildcard src/*/*.h)
HEADER_PATH = $(sort $(dir $(HEADER)))
OBJECTS = $(patsubst %.c,%.o,$(subst src,build/src,$(SRC)))
MAIN_OBJECTS = $(filter build/src/main/%.o, $(OBJECTS))
TEST_OBJECTS = $(filter build/src/test/%.o, $(OBJECTS))
TESTS = $(patsubst %Test.o,%.o, $(subst src/test,src/main, \
$(filter-out build/src/test/test_runners/%.o, $(TEST_OBJECTS))))
STUDY_SRC = $(notdir $(filter src/study/%.c, $(SRC)))
STUDY_OUT = $(STUDY_SRC:.c=.c.out)
UNITY_PATH = src/test/unity
UNITY_SRC_PATH = $(UNITY_PATH)/src
UNITY_EXTRAS_PATH = $(UNITY_PATH)/extras/src
UNITY = build/$(UNITY_SRC_PATH)/unity.o
UNITY_EXTRAS = build/$(UNITY_EXTRAS_PATH)/*.o
UNITY_OBJECTS = $(UNITY) $(UNITY_EXTRAS)


build/src/*/%.o : src/*/%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^
	@echo compiled $^


all : compile blank run


compile : start
	@make $(TARGET)
ifeq ($(TEST_OBJECTS),)
	@make end
else
	@make $(TEST_TARGET) end blank test
endif


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
	@$(CC) -o $@ $^ $(TESTS) $(UNITY_OBJECTS)
	@echo maked $@


init :
	@echo init ...
	@make clean
	@mkdir -p src/{main,study,test} src/test/test_runners $(UNITY_SRC_PATH) $(UNITY_EXTRAS_PATH)
	@echo maked src directory .
	@echo unity download start ...
	-@git clone https://github.com/ThrowTheSwitch/Unity.git
	@cp Unity/src/* $(UNITY_SRC_PATH)
	@cp Unity/extras/fixture/src/* $(UNITY_EXTRAS_PATH)
	@cp Unity/extras/memory/src/* $(UNITY_EXTRAS_PATH)
	@rm -rf Unity
	@echo unity download complete !
	@echo
	@make build
	@echo done .


initM :
	@echo init ...
	@make clean
	@mkdir -p src/{main,study}
	@echo maked src direcotry .
	@echo
	@make buildM
	@echo done .


build :
	@echo build start ...
	@mkdir -p build/src/main
ifneq ($(TEST_OBJECTS),)
	@mkdir -p build/src/test/test_runners build/$(UNITY_SRC_PATH) build/$(UNITY_EXTRAS_PATH)
	@echo maked build directory .
	@$(CC) -c -o $(UNITY) $(UNITY_SRC_PATH)/unity.c
	@$(CC) -I$(UNITY_SRC_PATH) -c -o build/$(UNITY_EXTRAS_PATH)/unity_fixture.o $(UNITY_EXTRAS_PATH)/unity_fixture.c
	@$(CC) -I$(UNITY_SRC_PATH) -c -o build/$(UNITY_EXTRAS_PATH)/unity_memory.o $(UNITY_EXTRAS_PATH)/unity_memory.c
	@echo maked unity object file .
else
	@echo maked build directory .
endif
	@echo
	-@make all
	@echo
	@echo build complete !


clean :
	@rm -rf build/ *.out src/*/*.o
	@echo deleted object and run files .
