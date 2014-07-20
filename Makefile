SRCDIR := interpreter/interpreter

all: bf

bf: $(SRCDIR)/main.c
	$(CC) -o $@ $^

clean:
	rm -f bf
