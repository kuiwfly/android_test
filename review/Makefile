APP = main
OBJS = btreetest.o
CC = g++ 
CCFLAGS = -Wall -O 
$(APP):$(OBJS)
	$(CC) $(OBJS) -o $(APP) 
$(OBJS):%o:%cpp
	$(CC) -c $(CCFLAGS) $< -o $@
clean:
	rm *.o main
