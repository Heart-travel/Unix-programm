/*
 * =====================================================================================
 *
 *       Filename:  signal_set_mask.c
 *
 *    Description:  This function is used to show the usage of sigprocmask.
 *
 *        Version:  1.0
 *        Created:  11/10/2014 08:36:50 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ZCG, 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <signal.h>

static void opt(int signo)
{
    printf("In signal process function!\n");
}

int main(void)
{
    
    struct sigaction act;

    act.sa_handler = opt;
    sigemptyset(&act.sa_mask);
    //act.sa_mask |= SA_INTERRUPT;
    act.sa_flags = SA_RESETHAND;

    sigaction(SIGINT, &act, NULL);
    
    sigset_t newmask, oldmask;

    sigemptyset(&newmask);
    sigaddset(&newmask, SIGINT);

    if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
        printf("SIG_BLOCK error!\n");

    printf("Start sleeping!\n");
    sleep(3);
    printf("Stop sleeping!\n");

    if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
        printf("SIG_SETMASK error!\n");

    printf("Start pausing!\n");
    pause();

    printf("Finish pause!\n");

    return 0;
}

