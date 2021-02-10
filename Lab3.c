#include <stdio.h>
#include <sys/types.h> 
#include <dirent.h>
#include <string.h>
char s_gets(char,int);
int main(void){
struct dirent *mydir; 
FILE *out;
DIR *dir_ds;
int cnt=0;
char dirName[20];
puts("Input dir name :");
s_gets(dirName,20);
if((dir_ds = opendir(dirName)) == NULL) { 
perror("Dir open error"); 
return 1;
}
puts("Then input out file name :");
s_gets(dirName,20);
out=fopen(dirName,"w");
while((mydir=readdir(dir_ds)) != NULL){
    cnt++; 
fprintf(out,"Файл - %s, inode = %ld\n", mydir->d_name,mydir->d_ino);
}
if(cnt==0)
    puts("No files");
puts("Конец каталога"); 
closedir(dir_ds); 
return 0;
}
char* s_gets(char*st,int cnt){ // функция для ввода строк
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
