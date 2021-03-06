#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 128
int main(int argc,char **argv){
    if(argc!=2){
        perror("Argc error\n");
        exit(EXIT_FAILURE);
    }
    static int i=1;
    FILE *in=fopen(argv[1],"r");
    if(in==NULL){
        perror("open()");
        exit(EXIT_FAILURE);
    }
    char buf[SIZE];
    setvbuf(in,buf,_IOFBF,SIZE);
    while(fgets(buf,sizeof(buf),in)!=NULL){
        printf("%d : %s\n",i,buf);
        i++;
    }
    fclose(in);
    return 0;
}
