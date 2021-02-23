#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc,char**argv){
    //sleep(1);
    int childfree,fd;
    fd = open("qqq.txt", O_WRONLY | O_CREAT | O_TRUNC);
    if(fd == -1)
    {
        perror("open()");
        exit(EXIT_FAILURE);
    }
    if(dup2(fd, STDOUT_FILENO) == -1)
    {
        perror("dup2()");
        exit(EXIT_FAILURE);
    }
    
    childfree=fork();
    if(childfree == -1)
    {
        perror("fork()");
        exit(EXIT_FAILURE);
    }
    if(childfree == 0)
    {
        sleep(1);
        execl(argv[1],argv[2],argv[3],argv[4],NULL);
    }
    wait(NULL);
    execl(argv[1],argv[2],argv[3],argv[4],NULL);
   // close(fd);
    return 0;
}
