#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    srand(time(NULL));
    int i,j;
    int vect[3]={0,0,0};
    int matr[3][3];
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            matr[i][j]=rand()%10;
    printf("Matr :");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            vect[i]+=matr[i][j];
            if(j%3==0)
            printf("\n");
        printf("%d ",matr[i][j]);
}
}
printf("\nVector1 = %d\nVector2 = %d\nVector3 = %d\n",vect[0],vect[1],vect[2]);
}
