SHELL = /bin/bash
.SUFFIXES:
.SUFFIXES: .cpp .hpp .o
CPP = g++
CPPFLAGS = -g -O0 -Wall -std=c++0x

all: clean palla

clean:
	rm -f palla *.o *~

palla: model.o environment.o gameobject.o gamestate.o

play: palla
	./palla

fullmemcheck: palla
	valgrind --leak-check=full ./palla

memcheck: palla
	valgrind ./palla

debug: palla
	gdb ./palla
