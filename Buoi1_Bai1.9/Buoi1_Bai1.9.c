#include <stdio.h>
int n, a[1001];
int main(){

    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%d", &a[i]);

    for (int i=1; i<=n; i++)
        for (int j=i; j<=n; j++){
            for (int k=i; k<=j; k++) printf("%d ", a[k]);
            printf("\n");
        }
}
