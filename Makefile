IDIR = include
CC = gcc
CFLAGS_C = -I$(IDIR) $(shell pkg-config --cflags raylib)
CFLAGS_L = -I$(IDIR) $(shell pkg-config --libs --cflags raylib)
EXE_NAME = prog

SRCDIR = src
ODIR = bin
LDIR = lib

_FRAMEWORKS = CoreVideo IOKit Cocoa GLUT OpenGL
FRAMEWORKS = $(patsubst %,-framework %,$(_FRAMEWORKS))

_DEPS =
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

SRC_FILES = $(wildcard $(SRCDIR)/*.c)
OBJ := $(patsubst $(SRCDIR)/%.c, $(ODIR)/%.o, $(SRC_FILES))

.PHONY: all build run clean

all: build

build: create_dirs $(EXE_NAME)

run: build
	./$(EXE_NAME)

create_dirs:
	@mkdir -p $(ODIR)

$(ODIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS_C)

$(EXE_NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS_L) $(LIBS) $(FRAMEWORKS)

clean:
	rm -f $(ODIR)/*.o $(EXE_NAME)
