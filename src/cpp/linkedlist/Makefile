CPPFLAGS = -Werror -Wall -pedantic -O1 -fsanitize=address,undefined

.PHONY = clean

client: linkedlist.o linkedlist.h

linkedlist.o: linkedlist.h

clean:
	rm -f *.o client