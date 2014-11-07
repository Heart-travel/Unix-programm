/*
 * =====================================================================================
 *
 *       Filename:  signal_v3.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/06/2014 08:00:29 PM
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

static int sig_int_flag;
static void sig_int(int signo);

int main(void)
{
    signal(SIGINT, sig_int);

    while(sig_int_flag == 0)
    {
        pause();
    }

    return 0;
}

static void sig_int(int signo)
{
    signal(SIGINT, sig_int);
    printf("Catch signal %d\n", signo);
    sig_int_flag = 1;
}
