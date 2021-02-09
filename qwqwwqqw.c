/* Сформировать файл, содержащий записи по результатам сдачи очередного эк- замена студентами группы. Сгруппировать записи по оценкам.*/
#include <stdio.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>
#include <errno.h> 
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
char* s_gets(char *st,int cnt); // прототип функции ввода 
struct exam {                  // создаем структуру с 2 полями
    char nameSurname[30];       // имя для студентов
    int grade;                  // оценка за экзамен
};
static int i=0;
int main(int argc, char**argv){
    struct exam stud[10];       // создаем массив структур с 10 элементами
    struct exam *pointer=&stud[0];  // для дальнейшего удобства(манипуляции с полями) создаем указатель на структуру
    FILE*fdIn; // указатель на файл
    int cnt,temp;
if (argc!=2){ // обработка ошибок , т е проверяем что в командную строку была введена команда ./a.out NameFile(выходной файл)
    perror("argc error");
    exit(EXIT_FAILURE); 
}
if((fdIn=fopen(argv[1], "w"))==NULL){ 
    perror("Open error");
    exit(EXIT_FAILURE);
}
    printf("Enter students name and surname (empty str to exit ) : ");
    while (s_gets((pointer+i)->nameSurname,30)!=NULL && (pointer+i)->nameSurname[0]!='\0'){ // вводим имя и фамилию студента (для выхода вводим пустую строку)
        printf("Him grade: ");   
        scanf(" %d",&(pointer+i)->grade); // через указатель задаем полям структуры значения
        while(getchar()!='\n') // т к сканф(функция) не обрабатывает пробелы и символы новой строки то ее нужно выбросить из потока ввода
            continue;    // для это используем функцию гетчар и цикл
            i++;
            printf("Enter students name and surname (empty str to exit ) : ");
    }
    for(cnt=0;cnt<i;cnt++){ // цикл сортировки оценок по возрастанию
        for(int j=1;j<i;j++){
            if(((pointer+cnt)->grade)<((pointer+j)->grade)){ // меняем местами если больше
                temp=(pointer+cnt)->grade;
                ((pointer+cnt)->grade)=(pointer+j)->grade;
                (pointer+j)->grade=temp;
            }
            }
    }
    for(cnt=0;cnt<i;cnt++){ // выводим в файл
        fprintf(fdIn,"%s %d\n",(pointer+cnt)->nameSurname,(pointer+cnt)->grade);
    }
    puts("Programm finished!\n");
    fclose(fdIn);
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
