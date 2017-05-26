#include <iostream>
using namespace std;
int main(){
	int n;
	int k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	int start=0;
	for(int i=0;i<k;i++){
		start=start+a[i];
	}
	int min=start;
//	cout<<start<<endl;
	int index=0;
	for(int i=1;i<=n-k;i++){
		start=start-a[i-1]+a[i+k-1];
//		cout<<start<<endl;
		if(start<min){
			 min=start;
			index=i;
		}
	}
	cout<<index+1;
}	
