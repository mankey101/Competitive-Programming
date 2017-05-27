#include <bits/stdc++.h>
using namespace std;
int LessThanEqualBinSearch( int key, int data[], const int len )
{
    int min = 0;
    int max = len-1;
    // var max = data.length - 1; // Javascript, Java conversion

    while( min <= max)
    {
        int mid = min + ((max - min) / 2);

        /**/ if (data[mid] < key)  min  = mid + 1;
        else if (data[mid] > key)  max  = mid - 1;
        else   /*data[mid] = key)*/return mid    ;
    }

    if( max < 0 )
        return 0;  // key < data[0]
    else
    if( min > (len-1))
        return -1; // key >= data[len-1] // KEY_NOT_FOUND
    else
        return (min < max)
            ? min
            : max + 1;
}

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,base;
		cin>>n>>base;
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		int query[base];
		for(int i=0;i<base;i++) cin>>query[i];
		sort(a,a+n);
		for(int k=0;k<base;k++){
			int count2=0;
			if(query[k]<=a[0]){
				 count2=n;
			} 
			else{
				int j=LessThanEqualBinSearch(query[k],a,n);
				cout<<"j is "<<j<<endl;
				int count=j,temj=j;
				if(j<0){ j=n; temj=n;}
				while(count>=1){
					count=count-(query[k]-a[j-1]);
					count--;
					if(count>=0) count2++; 
					j--;
				}	
				if(n-temj>0) count2=count2+n-temj;
			}	
		
		cout<<count2<<endl;
		}
	}
}	
