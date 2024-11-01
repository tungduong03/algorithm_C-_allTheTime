//Nguyen Tung Duong - 20210266
#include <stdio.h>

int main(){
    printf("Enter the number of elements: ");
    int n, a[100];
    scanf("%d",&n);
    for (int i=0; i<n; i++) scanf("%d", a+i);
    printf("The input array is:\n");
    for (int i=0; i<n; i++) printf("%d ", *(a+i));
    printf("\n");

    for (int i=0; i<n; i++)
        for (int j=i; j<n; j++)
            if (*(a+i)>*(a+j)) {
                int tmp;
                tmp = *(a+i);
                *(a+i)=*(a+j);
                *(a+j)=tmp;
        }
    printf("The sorted array is:\n");
    for (int i=0; i<n; i++) printf("%d ", *(a+i));
}
