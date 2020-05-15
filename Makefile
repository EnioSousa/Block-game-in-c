CC=gcc
CFLAGS=-I. -Wall -lncurses

DEPS = errorMessage.h point.h piece.h map.h interface.h engine.h logic.h

ODIR=./bin

_OBJ = game.o errorMessage.o point.o piece.o map.o interface.o engine.o logic.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -o $@ -c $< $(CFLAGS) 

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm $(ODIR)/*.o

