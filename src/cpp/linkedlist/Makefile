CPPFLAGS = -Werror -Wall -pedantic -O1 -fsanitize=address,undefined

.PHONY = clean

linkedlist.o: linkedlist.h

clean:
	rm -f *.o client

client: linkedlist.o linkedlist.h
