CC = g++
SRCMODULES = encoder.c rotary_encoder.c
OBJMODULES = $(SRCMODULES:.c=.o) 
LDFLAGS = -lpigpio
CFLAGS = -g -Wall -ansi
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@
prog: $(OBJMODULES)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)
run: prog
	./prog
clean:
	rm -f *.o prog
