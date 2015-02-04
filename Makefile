main.hex: main.c
	sdcc -mpic14 -p12f675 main.c --use-non-free
all: main.hex
	pk2cmd -Ppic12f675 -Fmain.hex -M
