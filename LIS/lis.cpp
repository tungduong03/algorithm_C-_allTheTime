
#include <iostream>
using namespace std ;

main()
{
	long long n , f[30001] , a[30001] , res = 0 ;
	cin >> n ;
	for( long long i=0;i<n;i++) {
		cin >> a[i] ;
		f[i] = 1 ;
		for( long long j=i-1;j>=0;j--)
			if ( f[j] + 1 > f[i] && a[i] > a[j] ) f[i] = f[j] + 1 ;
		if ( f[i] > res ) res = f[i] ;
	}
	cout << res << endl ;
}
