#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int n=s.length();
	int h=0;
	for(int i=0;i<=1;i++) h=h*10+s[i]-48;
	int min=0;
	for(int i=3;i<=4;i++) min=min*10+s[i]-48;
	int i=min;
	int j=h;
	int count=0;
	for( i=min;i<60;i++) {
		int t=j/10;
		int ti=i/10;
		if(t==i%10 && j%10 == ti)  break;
		if(i==59) {j=(j+1)%24; i=-1; }
		count++;
		
	}
	cout<<count;
			
}					
