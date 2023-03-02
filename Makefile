FLAGS= -Wall
CC= gcc
LIBS= -lpq
OBJECTS=objects
BUILD=build
SRC=src
INCLUDE=include

STATIC=$(BUILD)/libmsq-utils.a
SHARED=$(BUILD)/libmsq-utils.so

OBJECTS_FILES=$(OBJECTS)/utils.o

all: $(STATIC) $(SHARED)

$(STATIC): $(OBJECTS_FILES)
	ar rcs $@ $(OBJECTS_FILES)

$(SHARED): $(OBJECTS_FILES)
	$(CC) -shared $(FLAGS) $(OBJECTS_FILES) -lpq -o $@

$(OBJECTS)/%.o: $(SRC)/%.c $(INCLUDE)/*.h
	$(CC) $(FLAGS) -c -fPIC -o $@ $<

install: $(STATIC) $(SHARED)
	sudo cp $(SHARED) /usr/lib
	sudo mkdir -p /usr/include/msq-utils
	sudo cp $(INCLUDE)/*.h /usr/include/msq-utils

uninstall:
	sudo rm -rf /usr/include/msq-utils
	sudo rm -f /usr/lib/libmsq-utils.so

clean: uninstall
	rm -f $(OBJECTS)/*
	rm -f $(BUILD)/*