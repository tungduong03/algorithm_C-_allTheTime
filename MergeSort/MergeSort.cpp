#include <bits/stdc++.h>
using namespace std;
int arr[10];
void merge_sort(int arr[], int l, int m, int r)
{
    int n1=m-l+1;
    int n2=r-m;
    int L[n1];
    int R[n2];

    //khởi tạo 2 mảng chứa 2 phần của dãy lớn
    for (int i=0; i<n1; i++) L[i]=arr[l+i];
    for (int j=0; j<n2; j++) R[j]=arr[m+1+j];
    int i=0, j=0, k=l;

    //gộp 2 mảng, bằng cách so sánh phần tử đứng đầu tiên mỗi dãy đó là phần tử nhỏ nhất mỗi dãy
    while (i<n1 && j<n2)
    {
        if (L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
            k++;
        }
        else
        {
            arr[k]=R[j];
            j++;
            k++;
        }
    }

    //còn lại phần tử nào trong mảng thì tống nó vào dãy
    while (i<n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }
    while (j<n2)
    {
        arr[k]=R[j];
        j++;
        k++;
    }
}

void merge_(int arr[],int l,int r)
{
    if (l<r)
    {
        int m=l+(r-l)/2;
        merge_(arr,l,m);
        merge_(arr,m+1,r);
        merge_sort(arr,l,m,r);
    }
//chia để trị
}
int main()
{
    freopen("MergeSort.inp","r",stdin);
    freopen("MergeSort.out","w",stdout);
    int n;
    cin>>n;
    for (int i=0; i<n; i++) cin>>arr[i];
    merge_(arr,0,n-1);
    for (int i=0; i<n; i++) cout<<arr[i]<<" ";
}
