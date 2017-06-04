#include <bits/stdc++.h>
using namespace std;
#define N 1000000007
long long binser(long long* ar,long long q,long long beg,long long end){
	end--;
	while(beg<end){
		int mid=beg+(end-beg+1)/2;
		if(ar[mid]>q) end=mid-1;
		else beg=mid;
	}
	return beg;
}
int main(){
	int t;
	cin>>t;
	for(int ip=0;ip<t;ip++){
		long long p,q,r;
		cin>>p>>q>>r;
		long long arX[p],arY[q],arZ[r];
		for(long long i=0;i<p;i++) cin>>arX[i];
		for(long long i=0;i<q;i++) cin>>arY[i];
		for(long long i=0;i<r;i++) cin>>arZ[i];
		sort(arX,arX+p);
		sort(arZ,arZ+r);
		sort(arY,arY+q);
		long long fsum=0;
		if(arX[0]>arY[q-1] || arZ[0]>arY[q-1]){
			cout<<"0"<<endl;
			continue;
		}
		long long cumX[p],cumZ[r];
		cumX[0]=arX[0];
		cumZ[0]=arZ[0];
		for(long long i=1;i<p;i++) cumX[i]=cumX[i-1]+arX[i];
		for(long long i=1;i<r;i++) cumZ[i]=cumZ[i-1]+arZ[i];
		long long indexnX,indexnZ;
		for(long long i=0;i<q;i++){
			long long sumt;
			 indexnX=binser(arX,arY[i],0,p);
			 indexnZ=binser(arZ,arY[i],0,r);
			sumt=(cumX[indexnX]%N)*(cumZ[indexnZ]%N);
			fsum=(fsum+sumt)%N;
			sumt=(((arY[i]*arY[i])%N)*(((indexnX+1)*(indexnZ+1))%N))%N;
			fsum=(fsum+sumt)%N;
			sumt=((cumX[indexnX]%N)*(indexnZ+1) + (cumZ[indexnZ]%N)*(indexnX+1))%N;
			sumt=(sumt*arY[i])%N;
			fsum=(fsum+sumt)%N;
		}
	cout<<fsum%N<<endl;
	}
}
