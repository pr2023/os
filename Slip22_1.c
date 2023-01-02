#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
main(){
    int pid, retnice;/*retnice=return nice*/
    printf("press DEL to stop process\n");
    pid = fork();
    for (;;)
    {
        if (pid == 0)
        {
            retnice = nice(-5);
            printf("Child gets higher CPU priority %d\n", retnice);
            sleep(5);
        }
        else
        {
            retnice = nice(4);
            printf("Parent gets lower CPU priority %d\n", retnice);
            sleep(5);
        }
    }
}