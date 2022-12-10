#!/bin/sh

#./encoder_BDA -q encoder_data &
./keypad_BDA -q keypad_data &
./step_motor_BDA -q 1 step_motor_data &

ENC_READ="encoder_data"
KEY_READ="keypad_data"
MOT_WRITE="step_motor_data"

#while read line
#do
#	line >> $MOT_WRITE
#done < $ENC_READ &

while read line
do
	line >> $MOT_WRITE
done < $KEY_READ &
