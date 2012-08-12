OBJS=main.o
CC=gcc
CFLAGS=-Wall -g -O
main:$(OBJS)
	$(CC) $(OBJS) -o main -lpthread
$(OBJS):%o:%c
	$(CC) -c $(CFLAGS) $< -o $@
clean:
	rm -fr *.o *.symvers *.mod.c main
