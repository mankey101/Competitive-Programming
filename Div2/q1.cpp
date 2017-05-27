#include <bits/stdc++.h>
using namespace std;
int main(){
	long long int a,b;
	cin>>a>>b;
	int n1,n2;
	 n1=sqrt(a);	
	 n2=(sqrt(1+b*4)-1)/2;
	if(n1<=n2) cout<<"Vladik";
	else cout<<"Valera";
	
}
