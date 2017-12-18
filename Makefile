CC = gcc
CFLAGS = -Wall --pedantic -std=c99
OBJS = $(addsuffix .o, list_node menu list_menu)

all: main
main: $(OBJS) main.c
#implicit
list_node.o: list_node.h
#implicit
menu.o: menu.h
#implicit
list_menu.o: list_menu.h
#implicit

clean:
	rm -f main $(OBJS) *~

.PHONY: all clean