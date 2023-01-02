#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
 void main()
{
  int pid;
  pid=fork();
  printf("/n pid=%d",pid);
  if(pid==0)
 {
  printf("\nBefore parent process is terminated");
  printf("\nChild process with id%d,parent process with id %d",(int)getpid(),(int)getppid());
  sleep(1);
  printf("\nAfter parent process is terminated");
  printf("\nOrphan child process with id %d,parent process with id %d",(int)getpid(),(int)getppid());
   printf("\nChild is existing");
  exit(0);
  }
  else
  {
  printf("\n I am parent process with id %d\n",(int)getpid());
  printf("\n Parent is Existing");
  exit(0);
  }
} 
