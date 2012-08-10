OBJS=main.o
CC=gcc
CFLAGS=-Wall -O -g
main:$(OBJS)
	$(CC) $(OBJS) -o main -lpthread
$(OBGS):%o:%c
	$(CC) -c $(CFLAGS) $< -o $@
clean:
	rm -fr *.o main
