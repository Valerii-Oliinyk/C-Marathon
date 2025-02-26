CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -Iinc -Isrc
LDFLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lm
SRC = $(wildcard src/core/*.c src/levels/*.c src/menu/*.c src/*.c)
OBJ = $(SRC:.c=.o)
TARGET = a

build: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET) | cat -e

clean:
	rm -f $(OBJ) $(TARGET)