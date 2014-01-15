CC = gcc
OPTIONS = -Wall
BINARIES = keyword
OBJS = keyword.o keyword_cypher.o list.o

$(BINARIES): $(OBJS)
	$(CC) $(OPTIONS) $(OBJS) -o $(BINARIES)
     
keyword.o: keyword.c list.h keyword_cypher.h
	$(CC) $(OPTIONS) -c keyword.c

keyword_cypher.o: keyword_cypher.c keyword_cypher.h list.h
	$(CC) $(OPTIONS) -c keyword_cypher.c
	  
list.o: list.c list.h
	$(CC) $(OPTIONS) -c list.c
	                      
clean:
	rm -f *.o $(BINARIES)
      
     
