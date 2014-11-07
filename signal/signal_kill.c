/*
 * =====================================================================================
 *
 *       Filename:  signal_kill.c
 *
 *    Description:  show how to send a signal use "kill"
 *
 *        Version:  1.0
 *        Created:  11/05/2014 09:47:15 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ZCG
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <signal.h>
#include <sys/types.h>

static void sig_usr(int);

int main(void)
{
    if (signal(SIGUSR1, sig_usr) == SIG_ERR)
        printf("Can't catch SIGUSR1!\n");
    if (signal(SIGUSR2, sig_usr) == SIG_ERR)
        printf("Can't catch SIGUSR2!\n");
    sleep(5);
    kill(getpid(), SIGUSR1);
    sleep(3);
    kill(getpid(), SIGUSR2);

    return 0;
}

static void sig_usr(int signo)
{
    if(signo == SIGUSR1)
        printf("Receive SIGUSR1!\n");
    else if(signo == SIGUSR2)
        printf("Receive SIGUSR2!\n");
    else
        printf("Receive signal %d\n", signo);
}
