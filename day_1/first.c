#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
 {
  int pid;
  int fd[2];
  pipe(fd);

  switch(pid = fork())
   {
    case -1:
     printf("Error\n");
     return -1;

    case 0:
     close(fd[1]);
     char *c;
     read(fd[1], c, sizeof(char));
     printf("%s\n", c);
     char *string = "huehuehue";
     printf("%s\n",string);
     printf("Child's pid = %d\n", pid);
     exit(0);
     

    default:
     close(fd[0]);
     char *s = "Hi!";
     write(fd[0], s, sizeof(char));
     waitpid();
     printf("Parent's pid = %d\n", pid);
   }
 }