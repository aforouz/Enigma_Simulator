CC=gcc

CFLAGS=-I./src

DEPS = ./src/config.h

SRCS = ./src/*.c

OBJS = $(SRCS:.c=.o)

EXECUTABLE = ./bin/main.c

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -f $(OBJS) $(EXECUTABLE)
	
# To compile the Enigma project, navigate to the project directory in the terminal/CMD and type make. 
#To clean up the compiled files, type make clean.

