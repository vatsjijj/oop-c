exec = exp
CC = clang
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
CFLAGS = -std=c17 -O3 -march=native
LDFLAGS = -flto

$(exec): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(exec) $(LDFLAGS)

%.o: %.cc include/%.h
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	clear
	rm src/*.o