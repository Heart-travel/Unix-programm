/*
 * =====================================================================================
 *
 *       Filename:  signal_v2.c
 *
 *    Description:  This is a signal sample which use sigcation.
 *
 *        Version:  1.0
 *        Created:  11/05/2014 03:34:17 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ZCG 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <unistd.h>  
#include <stdio.h>  
#include <signal.h>  
  
void ouch(int sig)  
{  
    printf("\nOUCH! - I got signal %d\n", sig);  
}  
  
int main()  
{  
    struct sigaction act;  

    act.sa_handler = ouch;  
    sigemptyset(&act.sa_mask);              //创建空的信号屏蔽字，即不屏蔽任何信息  
    act.sa_flags = SA_RESETHAND;            //使sigaction函数重置为默认行为  
    
    sigaction(SIGINT, &act, 0);  
                
    while(1)  
    {  
        printf("Hello World!\n");  
        sleep(1);  
    }  
    return 0;  
}  
