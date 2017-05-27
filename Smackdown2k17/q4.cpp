#include <bits/stdc++.h>
using namespace std;
long long int min(long long int x,long long int y){
	if(x<y) return x;
	else return y;
}
long long int max(long long int x,long long int y){
	if(x<y) return y;
	else return x;
}
int main(){
	int t;
	cin>>t;
	for(int du=0;du<t;du++){
		long long int x1,y1,x2,y2,X1,X2,Y1,Y2;
		cin>>x1>>y1>>x2>>y2;
		cin>>X1>>Y1>>X2>>Y2;
		int m1,m2;
		if(y1==y2) m1=0;
		else m1=1;
		if(Y1==Y2) m2=0;
		else m2=1;				
		if(m1==m2){
			if(m1==0){
				if(y1==Y1){
					if((min(x1,x2)<=min(X1,X2) && max(x2,x1)>=min(X2,X1)) || (min(x1,x2)>=min(X1,X2) && min(x2,x1)<=max(X2,X1)) ){
						cout<<"yes"<<endl;
					}
					else cout<<"no"<<endl;
				}
				else cout<<"no"<<endl;
			}
			else{
				if(x1==X1){
					if((min(y1,y2)<=min(Y1,Y2) && max(y2,y1)>=min(Y2,Y1)) || (min(y1,y2)>=min(Y1,Y2) && min(y2,y1)<=max(Y2,Y1)) ){
						cout<<"yes"<<endl;
					}
					else cout<<"no"<<endl;	
				}
				else cout<<"no"<<endl;
			}			
		}
		else{
			if(x1==x2 && y1==y2){
				if(x1==X1 && (y1<=max(Y1,Y2) && y1>=min(Y1,Y2))) cout<<"yes"<<endl;
				else cout<<"no"<<endl;
			}
			else if(X1==X2 && Y1==Y2){
				if(x1==X1 && (Y1<=max(y1,y2) && Y2>=min(y1,y2))) cout<<"yes"<<endl;
				else cout<<"no"<<endl;
			}
			else{
				if((x1==X1 && y1==Y1) ||(x1==X2 && y1==Y2) ||(x2==X1 && y2==Y1) ||(x2==X2 && y2==Y2)) cout<<"yes"<<endl;
				else cout<<"no"<<endl;
			}
		}
	}
}
				
