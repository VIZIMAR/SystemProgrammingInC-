#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#define LEN 20
char* s_gets(char*,int);
    struct exam{
        char name[LEN];
        char surname[LEN];
        int grade;
    };
int main(int argc,char**argv){
    if(argc!=3){
        perror("Error, uncorect count command arguments");
        exit(EXIT_FAILURE);
    }
    FILE* fdIn,*fdOut;
    int cnt,i=0;
    printf("Input students count : ");
    scanf(" %d",&cnt); 
    if (cnt==0)
        exit(EXIT_FAILURE);
        while(getchar()!='\n') // очистить входной поток
            continue;
    if((fdIn=fopen(argv[1],"w"))==NULL){
            printf("%s ",argv[1]);
            perror("Open error");
            exit(EXIT_FAILURE); 
            }
    if((fdOut=fopen(argv[2],"w"))==NULL){
            printf("%s ",argv[2]);
            perror("Open error");
            exit(EXIT_FAILURE); 
            }        
    struct exam students[cnt];
    struct exam *ptr=&students[0];
    printf("Enter student name (press \'\\n\' at the beginning to exit :");
        while(i<cnt && s_gets((ptr+i)->name,LEN) && (ptr+i)->name[0]!='\0'){
            fprintf(fdIn,"%s ",(ptr+i)->name); //fputs((ptr+i)->name,fdIn);
            printf("Surname : ");
            s_gets((ptr+i)->surname,LEN);
            fprintf(fdIn,"%s ",(ptr+i)->surname); //fputs((ptr+i)->surname,fdIn);
            printf("Grade : ");
            scanf(" %d",&(ptr+i)->grade);
            while(getchar()!='\n')
            continue;
            fprintf(fdIn," %d\n",(ptr+i)->grade);
            if((ptr+i)->grade>70){
                fprintf(fdOut,"%s ",(ptr+i)->name);
                fprintf(fdOut,"%s ",(ptr+i)->surname);
                fprintf(fdOut," %d\n",(ptr+i)->grade);
            }
            i++;
            if(i<cnt)
                printf("Enter student name (press \'\\n\' to exit :");
            else
                break;
        }
    return 0;
}
char* s_gets(char*st,int cnt){
    char *find=fgets(st,cnt,stdin);
    if(find){
        find=strchr(st,'\n');
        if(*find=='\n')
            *find='\0';
        else while(getchar()!='\n')
            continue;        
    } else return NULL;
    return st; 
}
