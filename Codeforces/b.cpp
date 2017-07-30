#include <bits/stdc++.h>
using namespace std;
int main(){
	char a[10][10];
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++) cin>>a[i][j];
	}
	int count1=0,count2=0;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(a[i][j]=='X'){
				if(i<=5){
					for(int r=i;r<i+5;r++){
						if(a[r][j]=='.') count1++;
						if(a[r][j]=='X') count2++;
					}
					if(count1==1 && count2==4) {cout<<"YES"; return 0;}
					count1=0;
					count2=0;
				}
				if(j<=5){
					for(int r=j;r<j+5;r++){
						if(a[i][r]=='.') count1++;
						if(a[i][r]=='X') count2++;
					}
					if(count1==1 && count2==4) {cout<<"YES"; return 0;}
					count1=0;
					count2=0;
				}
				if(i>=4 && j<=5){
					int r=i,c=j;
					for(r=i;r>=i-4;r--){
						if(a[r][c]=='.') count1++;
						if(a[r][c]=='X') count2++;
						c++;
					}
					if(count1==1 && count2==4) {cout<<"YES"; return 0;}
					count1=0;
					count2=0;
				}
				if(i<=5 && j<=5){
					int r=i,c=j;
					for(r=i;r<i+5;r++){
						if(a[r][c]=='.') count1++;
						if(a[r][c]=='X') count2++;
						c++;
					}
					if(count1==1 && count2==4) {cout<<"YES"; return 0;}
					count1=0;
					count2=0;
				}
			}
		}
	}
	cout<<"NO";
	return 0;
}



