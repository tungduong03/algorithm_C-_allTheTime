//Nguyen Tung Duong - 0266

#include <stdio.h>
void reversearray(int arr[], int size){

    int l = 0, r = size - 1, tmp;
    while (l<r){
        tmp = arr[l];
        arr[l]=arr[r];
        arr[r]=tmp;
        l++;
        r--;
    }

}



void ptr_reversearray(int *arr, int size){

    int l = 0, r = size - 1, tmp;

    while (l<r){
        tmp = *(arr+l);
        *(arr+l)=*(arr+r);
        *(arr+r)=tmp;
        l++;
        r--;
    }

}
int main(){
    int arr[] = {9, 3, 5, 6, 2, 5};
    reversearray(arr, 6);
    for(int i = 0; i < 6; i++) printf("%d ", arr[i]);
    int arr2[] = {4, -1, 5, 9};
    ptr_reversearray(arr2, 4);
    for(int i = 0; i < 4; i++) printf("%d ", arr2[i]);

}
