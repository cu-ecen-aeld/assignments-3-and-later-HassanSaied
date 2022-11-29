#!/bin/bash

if [ $# -ne 2 ]
then
    echo 'Total number of arguments should be 2.'
    echo 'The order of the arguments should be'
    echo '  1) Path to a directory on the filesystem'
    echo '  2) Text string which will be searched within these files'
    exit 1
elif ! [ -d $1 ]
then
    echo 'Not a directory'
    exit 1
else
    numFiles=$( grep -rl "$2" $1/* | wc -l )
    numWords=$( grep -r "$2" $1/* | wc -l )
    echo "The number of files are $numFiles and the number of matching lines are $numWords"

fi



