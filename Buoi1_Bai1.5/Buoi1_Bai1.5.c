//Nguyen Tung Duong - 0266

#include <stdio.h>

double* maximum(double* a, int size){

    double *max;

    max = a;

    if (a==NULL) return NULL;

    else {
        for (int i=0; i<size; i++){
            if (a[i]> (*max) )
                *max = a[i];
        }
    }

    return max;

}
int main(){
    double arr[] = {1., 10., 2., -7., 25., 3.};
    double* max = maximum(arr, 6);
    printf("%.0f", *max);
}
