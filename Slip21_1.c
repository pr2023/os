//fork
//#include<sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int main(){
    printf("I am a parent: %d\n", (int)getpid());
    pid_t pid = fork();
    printf("Fork returned: %d\n", (int)pid);
    if (pid < 0){
        perror("Fork failed");
    }
    if (pid == 0){
        printf("I am the child with pid %d\n", (int)getpid());
        printf("Child process is existing\n");
        exit(0);
    }
    printf("I am the parent wating for the child process to end\n");
    wait(NULL);
    printf("Parent process is existing\n");
    return 0;
}
