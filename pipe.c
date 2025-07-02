#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
   int fd[2],n;
   char buffer[100];
   pid_t p;
   pipe(fd);
   p=fork();
   if(p<0)
   {
      perror("fork failed");
   }
   else if(p>0)
   {
     printf("parent passing mesg to child\n");
     write(fd[1],"hello\n",sizeof("hello\n"));
   }
   else
   {
     printf("child process received\n");
     n=read(fd[0],buffer,sizeof(buffer));
     write(1,buffer,n);
   }
}

// Output

/*
parent passing mesg to child
child process received
hello

*/










