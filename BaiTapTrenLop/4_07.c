//4.7
#include <stdio.h>

//tạo hàm tính a mũ b
//dùng vòng for để tính
double ex(double a, int b){
    double res =1;      //khởi tạo biến
    for(int i=0;i<b;i++ ){
        res *= a;       //res = res * a
    }
    return res;  //trả về kết quả res
}

//dùng vòng for giải quyết bài toán
int main(){
    double n,x,sum = 1; //khởi tạo biến n, x, sum
    scanf("%lf %lf",&n,&x); //nhập n, x

    if(n<=0|| n!= round(n)){  //kiểm tra điều kiện n nguyên dương
        printf("Error");    //in ra ERROR
        return 0;
    }

    for (int i=1;i<n+1;i++){
        sum += ex(x,i)*(i%2==1?-1:1);       //tính sum
    }
    printf("%lf",sum); //in kết quả
    return 0;
}

