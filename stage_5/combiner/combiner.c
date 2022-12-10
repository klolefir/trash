#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <bcm2835.h>

enum { buff_size = 1024 };

void handler(int s)
{
	int fd_err;
	int count
	char err_str[buff_size];
	fd_err = open("error_data", O_RDONLY);
	count = read(fd_err, err_str, sizeof(err_str));
	if(count < 0) {
		fprintf(stderr, "Read Err Error!\n");
		return 0;
	}
	err_str[count] = '\0';
	fprintf(stderr, "Error mesage from child: %s\n", err_str); 
	exit(0);
}

int main()
{
	time_t T = time(NULL);
	struct tm tm = *localtime(&T);

	int fd_enc, fd_key, fd_sm;
	int count;
	char angle_str[buff_size];
	char key_str[buff_size];
	int angle;

	signal(SIGUSR1, handler);

	fd_enc = open("encoder_data", O_RDONLY);
	fd_key = open("keypad_data", O_RDONLY);
	fd_sm = open("step_motor_data", O_WRONLY | TRUNC);

	//READ ENCODER
   ///////////////////////////
   //					   //
   /*      !!! \0 !!!      */
   //                      //
   //////////////////////////
	count = read(fd_enc, angle_str, sizeof(angle_str));
	if(count < 0) {
		fprintf(stderr, "Read Encoder Error!\n");
		return 0;
	}
	angle_str[count] = '\0';

	angle = atoi(angle_str);
	if(angle == 0) {
		fprintf("Atoi Error!\n");
		return 0;
	}

	printf("Time of rotation angle change: %02d:%02d:%02d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
	printf("Increment of the rotation angle: %d\n", angle);

	//STEP_MOTOR WRITE
	write(fd_sm, angle_str, sizeof(angle_str));	

	//READ KEYPAD
	count = read(fd_key, key_str, sizeof(key_str));
	if(count < 0) {
		fprintf(stderr, "Read Keypad Error!\n");
		return 0;
	}
	key_str[count] = '\0';

	pritnf("key = %s", key_str);

	return 0;
}

