#!/bin/bash

# Script that reads from /proc/sys/kernel/pid_max which stores the max value 
# a process id can take and prints it out

if [ -f /proc/sys/kernel/pid_max ]; then
	max_pid=$(cat /proc/sys/kernel/pid_max)
	echo "$max_pid"
else
	echo "Error: /proc/sys/kernel/pid_max file does not exist. Run on Linux"
fi
