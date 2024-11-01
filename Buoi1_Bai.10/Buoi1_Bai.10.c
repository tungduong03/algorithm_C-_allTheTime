#include <stdio.h>
#include <stdlib.h>
void allocate_mem(int n, int ***mt){
    int i;
    *mt = (int **)malloc(n * sizeof(int *));
    for (int i=0; i<n; i++)
        (*mt)[i] = (int *)malloc(n * sizeof(int));
}

void input(int n, int **mt){
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            scanf("%d", &mt[i][j]);
}

void output(int n, int **mt){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d ",mt[i][j]);
        }
        printf("\n");
    }
}

void add_void(int n, int **mt1,int **mt2,int **add){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            add[i][j]=mt1[i][j]+mt2[i][j];
        }
    }
}

void multi_void(int n, int **mt1, int **mt2, int **multi){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            multi[i][j] = 0;
            for (int k=0; k<n; k++){
                multi[i][j] += (mt1[i][k]*mt2[k][j]);
            }
        }
    }

}

void free_mem(int ***mt, int m) {
    int i;
    for (i = 0; i < m; i++) {
        free((*mt)[i]);
    }
    free(*mt);
}
int main(){
    int n, **mt1, **mt2, **add, **multi;
    scanf("%d",&n);
    allocate_mem(n, &mt1);
    input(n, mt1);
    allocate_mem(n, &mt2);
    input(n, mt2);
    allocate_mem(n, &add);
    allocate_mem(n, &multi);
    //output(n, mt1);
    //output(n, mt2);
    add_void(n, mt1, mt2, add);
    multi_void(n, mt1, mt2, multi);
    output(n, add);
    output(n, multi);
    free_mem(mt1, n);
    free_mem(mt2, n);
    free_mem(add, n);
    free_mem(multi, n);
}
