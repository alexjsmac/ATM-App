CC=g++
CFLAGS=-c -Wall -g -ggdb

ACCOUNT_SOURCES=account.cpp main.cpp user.cpp 

SOURCES=$(ACCOUNT_SOURCES)

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=atm

all : $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean :
	rm -rf *.o
	rm atm
