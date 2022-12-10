CC = gcc
SRCMODULES =
OBJMODULES = $(SRCMODULES:.c=.o) 
LDFLAGS = -D VAR6 -lbcm2835
CFLAGS = -g -Wall
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)
keypad_BDA: keypad.c $(OBJMODULES)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)
run: keypad_BDA
	./keypad_BDA
clean:
	rm -f *.o keypad_BDA
