#include <bits/stdc++.h>
using namespace std;
bool check(int x){
	int a[6];
	for(int i=5;i>=0;i--){
		a[i]=x%10;
		x/=10;
	}
	int sum=0;
	int sum2=0;
	for(int i=0;i<3;i++) sum+=a[i];
	for(int i=3;i<6;i++) sum2+=a[i];
	if(sum2==sum) return true;
	else return false;
}

int main(){
	int x;
	cin>>x;
	int i;
	for(i=x+1;;i++){
		if(check(i)) break;
	}
	cout<<i;
}
	
	
	
	

