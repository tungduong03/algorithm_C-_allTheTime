/*Nguyen Tung Duong - 0266*/

#include <stdio.h>
#include <stdlib.h>
void allocate_mem(int ***mt, int m, int n){
    int i;
    *mt = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++) {
        (*mt)[i] = (int *)malloc(n * sizeof(int));
    }
}

void in(int **mt, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n;j++){
            printf("mt[%d][%d] = ", i, j);
            scanf("%d", &mt[i][j]);
        }
    }
}

void out(int **mt, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%d ",mt[i][j]);
        }
        printf("\n");
    }
}

int process(int **mt, int m, int n){
    int tong = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if(mt[i][j] % 2 == 0){
                tong += mt[i][j];
            }
        }
    }
    return tong;
}

void free_mem(int **mt, int m, int n){
    int i;
    for (i = 0; i < m; i++) {
        delete[] mt[i];
    }
    delete[] mt;
}

int main(){

    int m, n, **mt;
    printf("Enter m, n = ");
    scanf("%d%d",&m,&n);
    allocate_mem(&mt, m, n);
    in(mt, m, n);
    out(mt, m, n);
    printf("The sum of all even elements is %d", process(mt, m, n));
    free_mem(mt, m, n);
    return 0;
}
