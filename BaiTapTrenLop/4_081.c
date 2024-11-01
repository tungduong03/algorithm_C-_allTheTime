//4.8
#include <stdio.h>

double ex(double a, int b){
    double res =1;
    for(int i=0;i<b;i++ ){
        res *= a;
    }
    return res;
}
double ex2(double a, int b){
    double res =1;
    for(int i=0;i<b;i++ ){
        res *= a--;
    }
    return res;
}

int isInt(double a){
	int res = 0;
	for(int i=0;i<a+1;i++){
		if(i+1==a){
			res  += 1;
		}
	}
	return res;
}

int main(){
    long double n,x,sum = 1;
    int a = scanf("%Lf",&n);
    int b = scanf("%Lf",&x);

    if(n<=0||isInt(n)==0||a<=0||b<=0){
        printf("Error");
        return 0;
    }

    for (int i=1;i<n+1;i++){
        sum += ex(x,i)/ex2(i,i);
    }
    printf("%Lf",sum);
    return 0;
}

