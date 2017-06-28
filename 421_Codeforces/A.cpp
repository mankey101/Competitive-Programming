#include <bits/stdc++.h>
using namespace std;
int main(){
	int c,vo,v1,a,l;
	cin>>c>>vo>>v1>>a>>l;
	int days=0;
	int pagesread=0;
	while(pagesread<=c){
		if(vo>=v1) vo=v1;
		pagesread=pagesread+vo;
		vo+=a;
		if(vo>=v1) vo=v1;
		days++;
		if(pagesread>=c) {
			cout<<days;
			return 0;
		}
		else pagesread-=l;
	}
}
