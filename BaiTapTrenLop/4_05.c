//4.5
#include <stdio.h>
#include <math.h>


int main(){
    double a,b,c,delta;    //khai báo biến a, b, c, delta
    scanf("%lf %lf %lf",&a,&b,&c);      //nhập a, b, c

    delta = b*b - 4*a*c;        //gán delta = b*b - 4*a*c

    //kiểm tra các trường hợp đặc biệt
    if (a == 0 && b != 0){     //nếu a = 0, b khác 0
        printf("%lf", -c/b);    //in ra kết quả
        return 0;
    }else if(a == 0 && b == 0 && c == 0){       //nếu a, b, c cùng bằng 0
        printf("Phuong trinh vo so nghiem");    //in ra kết quả
        return 0;
    }else if(a == 0 && b == 0 && c != 0){       //nếu a,b bằng 0, c khác 0
        printf("Phuong trinh vo nghiem");       //in ra kết quả
        return 0;
    }

    if(delta<0){      //kiểm tra delta
        printf("%lf+%lfi",-b/(2*a),sqrt(fabs(delta))/(2*a));    //in ra nghiệm 1
        printf("\n%lf-%lfi",-b/(2*a),sqrt(fabs(delta))/(2*a));  //in ra nghiệm 2
    }
    if(delta>0){        //kiểm tra delta
        printf("%lf",-b/(2*a)+sqrt(fabs(delta))/(2*a));         //in ra nghiệm 1
        printf("\n%lf",-b/(2*a)-sqrt(fabs(delta))/(2*a));          //in ra nghiệm 2
    }
    if(delta==0){           //kiểm tra delta
        printf("%lf",-b/(2*a)+sqrt(fabs(delta))/(2*a));         //in ra nghiệm kép
    }


    return 0;
}

