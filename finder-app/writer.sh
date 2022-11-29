#!/bin/bash

if [ $# -ne 2 ]
then
    echo 'Total number of arguments should be 2.'
    echo 'The order of the arguments should be'
    echo '  1) Path to a file on the filesystem'
    echo '  2) Text string which will be written within this file'
    exit 1
fi
mkdir -p "$( dirname $1 )"
touch $1
echo $2 > $1