#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


const int BSIZE = 100;
int main()
 {
  int pid;
  int fd[2];
  pipe(fd);
  char buf[BSIZE];

  switch(pid = fork())
   {
    case -1:
     printf("Error\n");
     return -1;

    case 0:
     close(fd[1]);
     ssize_t c;
     c = read(fd[1], buf, 20);
     printf("%s\n", (char *)c);
     char *string = "huehuehue";
     printf("%s\n",string);
     printf("Child's pid = %d\n", pid);
     close(fd[0]);
     exit(0);
     

    default:
     close(fd[0]);
     char *s = "Hi!";
     write(fd[0], "Hi!", 20);
     waitpid();
     printf("Parent's pid = %d\n", pid);
     close(fd[1]);
   }
 }