#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,q;
	cin>>n>>q;
	int query[q];
	for(int i=0;i<q;i++) cin>>query[i];
	int answer[4];
	answer[0]=0;
	//for answer 2 i.e 180 *
	int count1=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			 int t=(i*j)%7;
			 int l=((n+1-i)*(n+1-j))%7;
			if(t==1 || t==6 || t==0){
				if(l!=1 && l!=6 && l!=0){
				 count1++;			
//				cout<<"i is "<<i<<" j is "<<j<<endl;
				}
			}
			else{
				if(l==1 || l==6 || l==0){
				 count1++;
//				cout<<"i is "<<i<<" j is "<<j<<endl;
				}
			}
		}
	}
	answer[2]=count1;	 
	//for answer 1 i.e 90 *
	 count1=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int t=(i*j)%7;
			int l=(j*(n+1-i))%7;
			if(t==1 || t==6 || t==0){
                                if(l!=1 && l!=6 && l!=0) count1++;
                        }
                        else{
                                if(l==1 || l==6 || l==0) count1++;
                        }	
			
		}
	}
	answer[1]=count1;
	// for answer[3]
	 count1=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
				int t=(i*j)%7;
				int l=(i*(n+1-j))%7;
			if(t==1 || t==6 || t==0){
                                if(l!=1 && l!=6 && l!=0) count1++;
                        }
                        else{
                                if(l==1 || l==6 || l==0) count1++;
                        }			
		}
	}
	answer[3]=count1;

for(int i=0;i<q;i++){
	cout<<answer[(query[i]/90)%4]<<endl;
	}



}
