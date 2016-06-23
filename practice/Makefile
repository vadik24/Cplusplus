CC = g++
CFLAGS = -Wall -g
OFLAGS = -g
Object = smartPtr.o
test: $(Object)
	$(CC) -o $@ $(OFLAGS) $(OBJECT)
%.o:	%.c
	$(CC) -c $(CFLAGS) $< -o $@
clean:
	rm -f *.o test
