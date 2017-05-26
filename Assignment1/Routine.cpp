#include <iostream>
using namespace std;
int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}
int max(int a,int b){
	if(a>b) return a;
	else return b;
}
int min(int a,int b){
	if(a>b) return b;
	else return a;
}

int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
//	cout<<gcd(a,b)<<endl;
	float fi=(float)c/a;
	float se=(float)d/b;
	if(fi>se){
		int nu=b*c-a*d;
		int de=b*c;
		int gc=gcd(max(nu,de),min(nu,de));
		nu=nu/gc;
		de=de/gc;
		cout<<nu<<"/"<<de;
	}
	else if(fi<se){
		int nu=a*d-b*c;
		int de=a*d;
		int gc=gcd(max(nu,de),min(nu,de));
		nu=nu/gc;
		de=de/gc;
		cout<<nu<<"/"<<de;
	}
	else cout<<"0/1";
}
