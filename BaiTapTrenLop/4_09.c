//4.9
#include <stdio.h>
#include <math.h>

int main(){
    double x;   //khai báo x
    int n;      //khai báo n
    scanf("%lf %d",&x,&n);  //nhập x
    if(n<1||x<0){           //kiểm tra điều kiện n, x
        printf("Error");        //in ra ERROR
        return 0;
    }

    double re = sqrt(x);        //khai báo biến re
    while(n>1){
        re = sqrt(x + re);   //tính re
        n--;
    }

    printf("%.4lf",re);  //in kết quả
    return 0;
}
