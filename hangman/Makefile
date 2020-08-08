# Beginning of Makefile.

CC     = gcc
CFLAGS = -Ilib
OBJS   = obj/main.o obj/input.o obj/hangman.o obj/dictionary.o obj/llist.o

default: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o hangman

obj/main.o: src/main.c lib/hangman.h
	$(CC) $(CFLAGS) -c src/main.c -std=c99 -o $@

obj/input.o : src/input.c lib/input.h
	$(CC) $(CFLAGS) -c src/input.c -std=c99  -o $@

obj/hangman.o : src/hangman.c lib/hangman.h lib/dictionary.h lib/llist.h
	$(CC) $(CFLAGS) -c src/hangman.c -std=c99 -o $@

obj/dictionary.o : src/dictionary.c lib/dictionary.h lib/llist.h
	$(CC) $(CFLAGS) -c src/dictionary.c -std=c99 -o $@

obj/llist.o: src/llist.c lib/llist.h
	$(CC) $(CFLAGS) -c src/llist.c -std=c99 -o $@

clean:
	rm -f hangman $(OBJS)

# End of Makefile.