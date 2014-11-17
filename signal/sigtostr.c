/*
 * =====================================================================================
 *
 *       Filename:  sigtostr.c
 *
 *    Description:  This is used to show the usage of sig2str.
 *
 *        Version:  1.0
 *        Created:  11/14/2014 09:46:07 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ZCG 
 *   Organization:  
 *           Note:  This program cannot compile successfully.
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <signal.h>

int sig2str(int signo, char *str);

int main(void)
{
    //char str[SIG2STR_MAX];
    int i = 0;
    
    printf("SIGUSR1 = %d.\n", SIGUSR1);
    //i = sig2str(SIGINT, str);
    //printf("i = %d, signal is %s.\n", i, str);

    return 0;
}

