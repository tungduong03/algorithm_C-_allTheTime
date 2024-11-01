#include <stdio.h>
//dùng vòng for giải quyết bài toán
int main(){
    int a,check = 0;  //khai báo biến a, check
    scanf("%d",&a);   //nhập số nguyên a
    for(int i=2;i<(a/2 + 1);i++){
        if(a%i==0){          //kiểm tra chia hết
            check+=1;          //nếu a chia hết cho ước bất kì thì check tăng lên 1
        }
    }
    if(a==1||(a!=2 && check!= 0)||a<=0){     //kiểm tra điều kiện không phải snt
        printf("Khong phai so nguyen to");      //in ra kết quả
    }else {
        printf("La so nguyen to");          //in ra kết quả
    }
    return 0;
}
