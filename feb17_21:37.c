#include <stdio.h>
#include <sys/types.h> 
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
int main(int argc, char *argv[]){
    if(argc!=2){ // проверяем количество аргументов в командной строке , если не 2 аргумента то выходим
    perror("argc error"); // вывод ошибки
    exit(EXIT_FAILURE); // аварийный выход 
    }
    char *path=argv[1]; // наш указываемый файл который мы указываем через командную строку
    int rval=access(path,X_OK); // функция access()  она проверяет режим доступа , X_OK - флаг проверки на выполнение файла
    if(rval==0){ // если флаг X_OK присутвует то мы выходим , значит у нас есть права на выполнение
        printf("X_OK YES\n");
        exit(EXIT_SUCCESS); 
    }
    else if(rval==-1){ // если прав нет то мы из устанавливаем
        if(chmod(path,S_IXUSR|S_IXGRP|S_IXOTH)){ // S_IXUSR для владельца на выполнение|S_IXGRP для группы |S_IXOTH и для остальных 
        perror("Change mode error"); // -1 это ошибка а 0 это успешное выполнение
        exit(EXIT_FAILURE);
        }
        else 
        printf("Succes!\n"); // если права на выполнение имеются то мы выводим сообщение и программа завершается
    } 
      puts("Programm finished!");
return 0;
}
