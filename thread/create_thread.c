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
 *           Note: pthread 库不是 Linux 系统默认的库，连接时需要使用静态库 libpthread.a，
 *                  所以在使用pthread_create()创建线程，以及调用 pthread_atfork()函数建
 *                  立fork处理程序时，需要链接该库。
 *                  解决方法：在编译中要加 -lpthread参数
 *                  gcc -o create_thread creat_thread.c -lpthread

 *
 * =====================================================================================
 */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *newthread(void *str)
{
    printf("*********New thread : \n");
    return ((void *)0);
}

int main(void)
{
    int err;
    //char str[10] = "hello";
    //pid_t pid;
    pthread_t tid;

    printf("Before create thread.\n");
    err = pthread_create(&tid, NULL, newthread, NULL);
    printf("After create thread.\n");
    if (err != 0)
        printf("Create thread failed!\n");
    sleep(1);

    return 0;
}

