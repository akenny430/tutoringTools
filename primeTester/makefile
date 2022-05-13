CC=clang
INCLUDES=
CFLAGS=-g -Wall
LDFLAGS=-g
LDLIBS=

EXECUTABLE=prime

$(EXECUTABLE): main.o millerRabin.o messages.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

main.o: main.c millerRabin.h messages.h

millerRabin.o: millerRabin.c millerRabin.h

messages.o: messages.c messages.h 

.PHONY: clean 
clean:
	rm -rf *.o $(EXECUTABLE)

.PHONY: all 
all:
	clean $(EXECUTABLE)
