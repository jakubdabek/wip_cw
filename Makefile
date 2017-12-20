CC = clang
CFLAGS = -Wall --pedantic -std=c11
OBJS = $(addsuffix .o, list_node menu list_menu utility)

all: main
main: $(OBJS) main.c
#implicit
list_node.o: list_node.h
#implicit
menu.o: menu.h utility.h
#implicit
list_menu.o: list_menu.h utility.h
#implicit
utility.o: utility.h
#implicit

clean:
	rm -f main $(OBJS) *~

.PHONY: all clean