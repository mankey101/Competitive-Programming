#include <bits/stdc++.h>
using namespace std;
int main(){
	double pie=180.0;
	double n,a;
	cin>>n>>a;
	double max=pie-(2.0)*pie/n;
	double min=pie/n;
	int count=3;
	for(double i=pie-2*min;i>=min;i=i-min){
		if(a>max) break; 
		if(count==n) break;
		if((i-a) ==0) break;
		if((i-a)>0 && (i-min-a)<0){
			if(i-a > a+min-i) { count++; break;}
			else break;
		}
		count++;
	}
	cout<<"1 2 "<<count;
}
	
