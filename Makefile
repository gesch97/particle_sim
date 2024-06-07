IDIR =include
CC=gcc
CFLAGS=-I$(IDIR) $(shell pkg-config --libs --cflags raylib)
EXE_NAME =prog

SRCDIR=src

ODIR=bin
LDIR =lib

# LIBS=$(shell pkg-config --libs --cflags raylib)
# asd:
# 	echo $(CFLAGS)


_DEPS = hello.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = hello.o main.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXE_NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(EXE_NAME)
