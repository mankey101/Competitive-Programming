#include <bits/stdc++.h>
using namespace std;
#define ll	long long
ll ans;

bool DFS(ll i,ll b,ll prev,vector<ll>* adj,stack< pair<ll,ll> >& s,ll index){
	//cout<<i<<endl;
	if(i==b) {s.push(make_pair(i,index)); return true;}
	s.push(make_pair(i,index));
	set<ll> op;
	for(vector<ll>::iterator j=adj[i].begin();j!=adj[i].end();j++){
		if(op.find(*j)==op.end() && *j!=prev){
			op.insert(*j);
			if(DFS(*j,b,i,adj,s,j-adj[i].begin())==true) return true;
		}
	}
	s.pop();
	return false;
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		ll n,m;
		cin>>n;
		vector<ll>adj[n+1];
		vector<ll>wait[n+1];
		for(int i=1;i<n;i++){
			ll a,b,c;
			cin>>a>>b>>c;
			adj[a].push_back(b);
			adj[b].push_back(a);
			wait[a].push_back(c);
			wait[b].push_back(c);
		}
		cin>>m;
		for(int i=0;i<m;i++){
			stack<pair<ll,ll> > s;
			ll a,b,k;
			cin>>a>>b>>k;
			bool l=DFS(a,b,0,adj,s,-1);
			int cnt=0;
			
			while(!s.empty()){
				pair<ll,ll> t=s.top();
				s.pop();
				if(s.empty()) break;
				pair<ll,ll> pre=s.top();
				if(wait[pre.first][t.second]<=k) ans=ans^wait[pre.first][t.second];
			}
			cout<<ans<<endl;
			ans=0;
		}
	}
}
		
