//4.8
#include <stdio.h>
#include <math.h>
int main(){
    double n,x;        //khởi tạo biến n, x
    double sum = 1;  //khởi tạo sum
    scanf("%Lf",&n);        //nhập n
    scanf("%Lf",&x);        //nhập x

    if( (n<=0) || (n != round(n))  ){  //kiểm tra điều kiện n nguyên dương
        printf("Error");    //in ra ERROR
        return 0;
    }
    double mu=1;  //tạo biến tính x^i
    for (int i=1; i<=n; i++){
        mu = mu * x;    //tính x^i
        sum = sum + mu/i;  //tính sum
    }
    printf("%Lf",sum);   //in ra kết quả
    return 0;
}

