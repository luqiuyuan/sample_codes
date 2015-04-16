INC = \
	-IC:\Program\ Files\ffmpeg\ffmpeg-x86\include

LINK_DIR = \
	-LC:\Program\ Files\ffmpeg\ffmpeg-x86\lib

LIBS = \
	-lavcodec \
	-lavutil

all:	decoding_encoding.exe

decoding_encoding.exe:	decoding_encoding.o
						gcc decoding_encoding.o -o decoding_encoding.exe $(LINK_DIR) $(LIBS)

decoding_encoding.o:	decoding_encoding.c
						gcc -c decoding_encoding.c $(INC)

clean:
	del decoding_encoding.exe decoding_encoding.o