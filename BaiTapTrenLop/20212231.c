#include <stdio.h>
#include <math.h>
int main(){
    double x;
    int y;
    scanf("%lf",&x);
    scanf("%d",&y);
    if (y<=0) printf("Error");
    else {
        double sum=0;
        sum = pow(y,7) + pow(x,5)*pow(y,5) + pow(x,4)*pow(y,3) + pow(x,2)*pow(y,2) + abs(x) + sqrt(y);
        printf("%.4lf",sum);
    }
}
