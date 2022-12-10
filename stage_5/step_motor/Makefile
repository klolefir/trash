CC = gcc
SRCMODULES =
OBJMODULES = $(SRCMODULES:.c=.o) 
LDFLAGS = -lbcm2835
CFLAGS = -g -Wall
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)
step_motor_BDA: step_motor.c $(OBJMODULES)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)
run: step_motor_BDA
	./step_motor_BDA
clean:
	rm -f *.o step_motor_BDA
