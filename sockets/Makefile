# the compiler
CC=g++
# options 
CFLAGS=-std=c++11 -c 

SOURCES_C=client.cpp
SOURCES_S=server.cpp

OBJECTS_C=$(SOURCES_C:.cpp=.o)
OBJECTS_S=$(SOURCES_S:.cpp=.o)

LDFLAGS=-L/usr/local/lib

EXECUTABLE_C=client
EXECUTABLE_S=server

all: server client

client: $(SOURCES_C)  $(EXECUTABLE_C)

server: $(SOURCES_S)  $(EXECUTABLE_S)

$(EXECUTABLE_C): $(OBJECTS_C) 
	$(CC) $(OBJECTS_C) -o $@ $(LDFLAGS)

$(EXECUTABLE_S): $(OBJECTS_S) 
	$(CC) $(OBJECTS_S) -o $@ $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS_S) $(EXECUTABLE_S) $(OBJECTS_C) $(EXECUTABLE_C)