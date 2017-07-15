#include <bits/stdc++.h>
using namespace std;
struct data{
	int date;
	int index;
	int sad;
};
struct bySad{

	bool operator() (const data &a,const data &b) const{
		return a.sad<b.sad;
	}
};
bool compare(data &lhs,data &rhs){
	return lhs.date<rhs.date;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		priority_queue<data,vector<data>,bySad > q;
		data prof[n];
		bool dates[d+1];
		long long total=0;
		int hours[n];
		for(int i=0;i<n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			prof[i].date=x;
			prof[i].index=i;
			hours[i]=y;
			prof[i].sad=z;
			total+=(long long)z*(long long)y;
		}
		sort(prof,prof+n,compare);
		int i=0,j=1;
		while(j<=d){
			if(total==0) break;
			while(i<n && prof[i].date==j) q.push(prof[i++]); 
			if(q.empty()) {j++; continue;}
			data curr=q.top();
			//couti<<curr.index<<endl;
			hours[curr.index]--;
			if(hours[curr.index]==0)q.pop();
			total-=curr.sad;
			//cout<<total<<" curr "<<endl;
			j++;
		}
		cout<<total<<endl;	
	}
}

