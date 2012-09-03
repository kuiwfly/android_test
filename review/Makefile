APP = main
#OBJS = main.o
OBJS = linktest.o
#CC = g++ 
CC = gcc 
CCFLAGS = -Wall -O 
$(APP):$(OBJS)
	$(CC) $(OBJS) -o $(APP) 
#$(OBJS):%o:%cpp
$(OBJS):%o:%c
	$(CC) -c $(CCFLAGS) $< -o $@
clean:
	rm *.o main
