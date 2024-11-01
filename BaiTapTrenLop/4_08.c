//4.8
#include <stdio.h>
#include <math.h>
int main(){
    double n,x;        //khởi tạo biến n, x
    double sum = 1;  //khởi tạo sum
    scanf("%lf %lf",&n, &x);        //nhập n, x
    if( (n<=0) || (n != round(n))){  //kiểm tra điều kiện n nguyên dương
        printf("Error");    //in ra ERROR
        return 0;
    }
    int gt=1;   //tao biến tính giai thừa
    for (int i=1; i<=n; i++){
        gt = gt * i;       //tính giai thừa
        sum = sum + (pow(x,i)/gt);  //tính sum
    }
    printf("%lf",sum);   //in ra kết quả
    return 0;
}
