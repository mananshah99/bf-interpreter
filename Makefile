CFLAGS := -Wall -Werror
SRCDIR := interpreter/interpreter

all: bf

bf: $(SRCDIR)/main.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f bf
