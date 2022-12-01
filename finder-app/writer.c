#include <stdlib.h>
#include <syslog.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#define NUM_ARGS 3

int main(int argc, char ** argv){
    openlog(NULL,0,LOG_USER);

    if(argc != NUM_ARGS){
        puts("Total number of arguments should be 2.");
        puts("The order of the arguments should be");
        puts("  1) Path to a file on the filesystem");
        puts("  2) Text string which will be written within this file");
        syslog(LOG_ERR,"Number of args %d while it should be %d",argc,NUM_ARGS);
        exit(1);
    }
    FILE * fptr = fopen(argv[1],"w");
    if(fptr == NULL){
        perror("Couldn't write file");
        syslog(LOG_ERR,"Couldn't open file with err %s",strerror(errno));
        exit(1);
    }
    syslog(LOG_DEBUG,"Writing %s to %s",argv[2],argv[1]);
    fprintf(fptr,"%s",argv[2]);
    fclose(fptr);
    closelog();

}