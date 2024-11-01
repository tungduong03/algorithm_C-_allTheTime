//Nguyen Tung Duong - 0266
/*Bài 1.4. Viết hàm countEven(int*, int)
nhận một mảng số nguyên và kích thước của mảng,
trả về số lượng số chẵn trong mảng???*/
#include <stdio.h>
int counteven(int* arr, int n){
    int countt=0;
    for (int i=0; i<n; i++){
        if (arr[i]%2==0) countt++;
    }
    return countt;
}
int main(){
    int arr[] = {1, 5, 4, 8, 10, 6, 7, 2};
    printf("%d",counteven(arr, 8));

}
