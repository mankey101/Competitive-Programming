#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int ip=0;ip<t;ip++){
		int n,k;
		cin>>n>>k;
		set<int> myset;
		vector<int> a[n];
		for(int i=0;i<n;i++){
			int li;
			cin>>li;
			for(int j=0;j<li;j++){
				int x;
				cin>>x;
				 a[i].push_back(x);
			}
		}
		int count=0;
		for(int i=0;i<n-1;i++){
			if(a[i].size()==k){ count=count+n-i-1;
			continue;}
			for(int j=i+1;j<n;j++){
				int size1=a[i].size();
				int size2=a[i].size();
				if(size1+size2<k) continue;
				for(vector<int>::iterator it=a[i].begin();it!=a[i].end();it++) myset.insert(*it);
				for(vector<int>::iterator it=a[j].begin();it!=a[j].end();it++) myset.insert(*it);
				if(myset.size()==k) count++;
				myset.clear();
			}
		}
	cout<<count<<endl;
	}
}
		
