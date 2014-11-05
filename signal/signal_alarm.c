/*
 * =====================================================================================
 *
 *       Filename:  signal_alarm.c
 *
 *    Description:  This file is a signal example using alarm,
 *
 *        Version:  1.0
 *        Created:  11/05/2014 03:49:41 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ZCG
 *   Organization:  
 *
 * =====================================================================================
 */
#include <unistd.h>  
#include <sys/types.h>  
#include <stdlib.h>  
#include <stdio.h>  
#include <signal.h> 

static int alarm_fired = 0;

void ouch(int sig)
{
    alarm_fired = 1;
}

int main(void)
{
    pid_t pid;

    if ((pid = fork()) < 0)
    {
        return -1;
    }
    else if(pid == 0)
    {
        sleep(5);
        kill(getppid(), SIGALRM);
    }
    else
    {
        signal(SIGALRM, ouch);

        while(!alarm_fired)
        {
            printf("Hello, world!\n");
            sleep(1);
        }

        if(alarm_fired)
            printf("\n I get a signal = %d.\n", SIGALRM);
    }
    return 0;
}
