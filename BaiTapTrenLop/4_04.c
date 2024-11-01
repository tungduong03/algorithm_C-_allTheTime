//4.4
#include <stdio.h>
//dùng vong for tìm UCLN
//BCNN = tích 2 số chia cho UCLN
int main(){
    int a,b,UCLN,BCNN=0;    //khai báo biến a, b, UCLN, BCNN
    scanf("%d %d",&a,&b);   //nhập 2 biến a, b
    if(a<=0||b<=0){         //kiểm tra điều kiện số nguyên dương
        printf("ERROR");    //in ra ERROR
        return 0;
    }
    for(int i=1;i<( ((a<b)?a:b) + 1);i++){
        if(a%i==0 && b%i==0){           //kiểm tra a và b có cùng chia hết i hay ko
            UCLN=i;         //gán UCLN = i
        }
    }

    BCNN = a*b/UCLN;           //gán BCNN = a*b/UCLN

    printf("%d\n",UCLN);        //in UCLN
    printf("%d",BCNN);          //in BCNN
    return 0;
}
