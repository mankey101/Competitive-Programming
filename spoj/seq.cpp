#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	char yo[n-1];
	for(int i=1;i<n;i++){
		if(a[i]>a[i-1]) yo[i-1]='1';
		else if(a[i]<a[i-1])  yo[i-1]=0;
		else yo[i-1]='0';
	}
	for(int i=0;i<n-1;i++){
		if(yo[i]=='1'){
			for(int j=i+1;j<n-1;j++){
				if(yo[j]==0){
					for(int k=j+1;k<n-1;k++){
						if(yo[k]=='1' || yo[k]=='0'){
							cout<<"No";
							return 0;
						}
					}
					cout<<"Yes";
					return 0;
				}
				else if(yo[j]=='0'){
					for(int k=j+1;k<n-1;k++){
						if(yo[k]!=0){
							cout<<"No";
							return 0;
						}
					}
					cout<<"Yes";
					return 0;
				}
			}
		cout<<"No";
		return 0;
		}
		
		else if(yo[i]==0){
			for(int j=i+1;j<n-1;j++){
				if(yo[j]=='1'){
					for(int k=j+1;k<n-1;k++){
						if(yo[k]==0 || yo[k]=='0'){
							cout<<"No";
							return 0;
						}
					}
					cout<<"Yes";
					return 0;
				}
				else if(yo[j]=='0'){
					for(int k=j+1;k<n-1;k++){
						if(yo[k]!='1'){
							cout<<"No";
							return 0;
						}
					}
					cout<<"Yes";
					return 0;
				}
			}
		cout<<"No";
		return 0;
		}
		
		else{
			if(yo[1]=='1'){
				for(int j=2;j<n;j++){
					if(yo[j]!='1'){
						cout<<"No";
						return 0;
					}
				}
				cout<<"Yes";
				return 0;
			}
			else if(yo[1]==0){
				for(int j=2;j<n;j++){
					if(yo[j]!=0){
						cout<<"No";
						return 0;
					}
				}
				cout<<"Yes";
				return 0;
			}
			else return 0;
		}
	}
}
		
