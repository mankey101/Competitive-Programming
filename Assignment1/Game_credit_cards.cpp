#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	char a[n],b[n];
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	sort(a,a+n);
	sort(b,b+n);
	int count=0;
	int j=0;
	for(int i=0;j<n;i++){
		if(b[j]>a[i]) count++;
		else {
			int flag=0;
			for(int k=j;k<n;k++){
				j=k;
				if(b[k]>a[i]){flag=1; break;}
			}
			if(flag==1)  count++;
		}
		j++;
	}
	j=n-1;
	int k=0;
	int count1=0;
	for(int i=n-1;i>=0;i--){
		if(b[j]>=a[i]) j--;
		else{
			count1++;
			k++;
		}
	}	
	cout<<count1<<endl;	
	cout<<count;
					
}
		
