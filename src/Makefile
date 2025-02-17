CC = gcc
CFLAGS = -Wall -Wextra 

SRC = $(wildcard *.c)
SRC_OBJ = $(SRC:.c=.o)

TARGET = main

all: $(TARGET) start clang-format

$(TARGET): $(SRC_OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

start: $(TARGET)
	./main

clang-format:
	clang-format -n *.c *.h
	
clean:
	rm -f *.o main

re: clean all


