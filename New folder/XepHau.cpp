#include <bits/stdc++.h>
using namespace std;
int a[20];
bool Ok(int x2,int y2){
	//kiểm tra cách đặt có thỏa mãn không
	for(int p = 1; p < x2 ;p++)
		if(a[p] == y2 || abs(p-x2) == abs(a[p] - y2) )   //a[p] = y2 là cùng hàng, (p,x2 là cột, a[p],y2 là hàng) hiệu abs bằng nhau thì cùng 1 đường chéo
			return false;
	//Nếu kiểm tra hết các trường hợp vẫn không sai thì trả về true
	return true;
}

void Xuat(int n){
	//in ra một kết quả
	for(int i=1;i<=n;i++)
		cout<<a[i];
	cout<<endl;
}

void Try(int i,int n){
	for(int j = 1;j<=n;j++){
		// thử đặt quân hậu vào các cột từ 1 đến n
		if(Ok(i,j)){
			//nếu thỏa mãn thì lưu lại vị trí
			a[i] = j;
                        //nếu đặt xong quân hậu thứ n thì xuất ra một kết quả
			if(i==n) Xuat(n);
			Try(i+1,n);
		}
	}
}

int main(){
	int n = 8;
	Try(1,n);
	return 0;
}
