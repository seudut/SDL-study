CFLAGS = -Wall `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs`
CC = gcc

%: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o "$@.out"
