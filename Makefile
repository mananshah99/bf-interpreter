CFLAGS := -Wall -Werror

all: bf

bf: main.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f bf
