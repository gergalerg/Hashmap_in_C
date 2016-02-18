GCC=gcc
CFLAGS=-g -Wall 
TARGET=main
SOURCES:=main.c hashmap.c darray.c hashmap_algos.c
DEPS:=darray.h hashmap.h hashmap_algos.h
# Math libraries
# MATH:=-lm
OBJECTS:=$(SOURCES:.c=.o)

%.o: %.c
	@echo "Making objects! Input = " $< "OUtput = " $@
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all
all: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET) 

.PHONY: clean
clean:
	rm $(TARGET) $(OBJECTS)
