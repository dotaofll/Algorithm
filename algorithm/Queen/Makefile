CC = g++
CFLAGS = -c -w -O2
SOURCES=queen.cpp
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=queen

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *o queen
	rm -rf Out.txt