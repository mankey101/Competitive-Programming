#include <bits/stdc++.h>
using namespace std;
struct sort_pred {
    bool operator()(pair<int,int> &left, pair<int,int> &right) {
        return left.second < right.second;
    }
};
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		vector< pair<int,int> > bag;
		int n,w;
		cin>>n>>w;
		int temp1[n];
		int temp2[n];
		for(int i=0;i<n;i++) cin>>temp1[i];
		for(int y=0;y<n;y++){
			 cin>>temp2[y];
			cout<<temp2[y]<<" "<<y<<endl;
		}
		cout<<"ji"<<endl;
		for(int i=0;i<n;i++) bag.push_back(make_pair(temp1[i],temp2[i]));
		sort(bag.begin(), bag.end(), sort_pred());
		int dat[w+1];
		memset(dat,0,w+1);
		dat[bag[0].second]=bag[0].first;
		int u=bag[0].second+1;
		while(u<=w){
			int flag=0;
			int k=0;
			for(int j=bag[k].second;j<=u;k++){
				if((u!=j && dat[u-j] && u!=2*j) || u==j){
					flag=1;
					if(dat[u-j]+bag[j].first>dat[j]) dat[j]= dat[u-j]+bag[j].first;
				}
			}
			if(flag==0) dat[u]=0;
			u++;
		}
		for(int i=w;i>=bag[0].second;i--)  {cout<<dat[i]<<endl;}
	}
}
