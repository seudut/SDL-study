CFLAGS = -Wall `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lsdl2_mixer
CC = gcc

%: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@.out
