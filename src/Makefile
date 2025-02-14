CC = gcc
CFLAGS = -Wall -Werror -Wextra 

SRC = $(wildcard *.c)
SRC_OBJ = $(SRC:.c=.o)

TARGET = main

all: $(TARGET) start

$(TARGET): $(SRC_OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

start: $(TARGET)
	./main

clean:
	rm -f *.o main

re: clean all


