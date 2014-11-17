/*
 * =====================================================================================
 *
 *       Filename:  create_thread.c
 *
 *    Description:  This program is used to show how to create a thread.
 *
 *        Version:  1.0
 *        Created:  11/17/2014 08:47:27 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ZCG, 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *newthread(void *str)
{
    printf("New thread : \n");
    return ((void *)0);
}

int main(void)
{
    int err;
    char str[10] = "hello";
    pid_t pid;
    pthread_t tid;

    printf("Before create thread.\n");
    err = pthread_create(&tid, NULL, newthread, NULL);
    printf("After create thread.\n");
    if (err < 0)
        printf("Create thread failed!\n");

    return 0;
}

