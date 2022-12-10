#!/bin/sh

./encoder_BDA -q encoder_data &
./keypad_BDA -q keypad_data &
./step_motor_BDA -q 1 step_motor_data &
./combiner

