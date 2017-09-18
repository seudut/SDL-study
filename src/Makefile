CC = gcc
EXT=
CFLAGS = -Wall `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` $(EXT)

%:%.c
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@ && ./$@

05_play_audio: EXT:= -lsdl2_mixer
