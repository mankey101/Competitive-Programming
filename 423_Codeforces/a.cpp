#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,a;
	double b;
	cin>>n>>a>>b;
	int notServed=0;
	int b2=(int) b;
	for(int i=1;i<=n;i++){
		int typ;
		cin>>typ;
		if(typ==2){
		       if(b2>0){b2--; b--;}
		       else notServed+=2;
		}
		else{
			if(a>0) a--;
			else if(b>0) {b-=0.5; b2--;}
			else notServed++;
		}
	}
	cout<<notServed;
}
		
