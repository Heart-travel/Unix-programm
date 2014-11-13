/*
 * =====================================================================================
 *
 *       Filename:  signal_system.c
 *
 *    Description:  This is used to discuss "system" with or without the function of 
 *                  processing signala.(P276)
 *
 *        Version:  1.0
 *        Created:  11/13/2014 08:22:17 PM
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
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>

int system(const char *cmdstring)
{
    pid_t pid;
    int status;

    if (cmdstring == NULL)
        return 1;

    if ((pid = fork()) < 0) {
        status = -1;
    } else if (pid == 0) {
    execl("/bin/sh", "sh", "-c", cmdstring, (char *)0);
    _exit(127);
    } else {
        while (waitpid(pid, &status, 0) < 0) {
            if (errno != EINTR) {
                status = -1;
                break;
            }
        }
    }

    return status;
}

static void sig_int(int signo)
{
    printf("Caught SIGINT!\n");
}

static void sig_chld(int signo)
{
    printf("Caught SIGCHLD!\n");
}

int main(void)
{
    if (signal(SIGINT, sig_int) == SIG_ERR)
        printf("signal(SIGINT) error!\n");
    if (signal(SIGCHLD, sig_chld) == SIG_ERR)
        printf("signal(SIGCHLD) error!\n");

    if (system("/bin/ed") < 0)
        printf("System() error");

    return 0;
}
