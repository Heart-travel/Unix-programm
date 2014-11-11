/*
 * =====================================================================================
 *
 *       Filename:  signal_suspend.c
 *
 *    Description:  This function is used to show the usage of sigsuspend.
 *
 *        Version:  1.0
 *        Created:  11/10/2014 09:21:36 PM
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

static void sig_int(int);

int main(void)
{
    sigset_t newmask, oldmask, waitmask;

    printf("Program start: \n");

    if (signal(SIGINT, sig_int) == SIG_ERR)
        printf("signal(SIGINT) error!\n");
    sigemptyset(&waitmask);
    sigaddset(&waitmask, SIGUSR1);
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGINT);

    if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
        printf("SIG_BLOCK error!\n");

    printf("In critical region: \n");
    
    alarm(3);

    if (sigsuspend(&waitmask) != -1)
        printf("sigsuspend error!\n");

    if (sigismember(&waitmask, SIGINT))
        printf("SIGINT in waitmask.\n");
    if (sigismember(&waitmask, SIGUSR1))
        printf("SIGUSR in waitmask.\n");
    if (sigismember(&newmask, SIGINT))
        printf("SIGINT in newmask.\n");
    if (sigismember(&newmask, SIGUSR1))
        printf("SIGUSR1 in newmask.\n");
    
    if (sigprocmask(SIG_SETMASK, &oldmask, NULL))
        printf("SIG_MASK error!\n");

    printf("Program exit!\n");

    return 0;
}

static void sig_int(int signo)
{
    printf("In sig_int : %d\n", signo);
}
