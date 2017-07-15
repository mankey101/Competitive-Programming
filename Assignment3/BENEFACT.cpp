#include <bits/stdc++.h>
using namespace std;
#define ll	long long
ll DFS(ll prev,ll s,vector< ll >* adj,vector<ll>* leni, ll* dist,ll* visit,ll india){
	ll max=0,max2=0;
	visit[s]=true;
	for(vector<ll >::iterator it=adj[s].begin();it!=adj[s].end();it++){
		if(visit[(*it)]==false){
			ll indi;
			indi=it-adj[s].begin();	
			ll m=DFS(s,(*it),adj,leni,dist,visit,indi);
			if(m>max) {
				max2=max;
				max=m;
			}
				
			else if(m>max2){
				max2=m;
			}
		}
	}
	dist[s]=max+max2;
	if(prev!=0) return max+leni[prev][india];
	else return 0;
}
			
			


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll visit[n+1];
		for(int i=1;i<=n;i++) visit[i]=false;
		vector<ll > adj[n+1];
		vector<ll> leni[n+1];
		for(ll i=0;i<n-1;i++){
			ll a,b,len;
			cin>>a>>b>>len;
			adj[a].push_back(b);
			leni[a].push_back(len);
			adj[b].push_back(a);
			leni[b].push_back(len);
		}
		ll dist[n+1];
		for(int i=1;i<=n;i++) dist[i]=0;
		ll l=DFS(0,1,adj,leni,dist,visit,0);
		ll temp=0;
		for(ll i=1;i<=n;i++){
			if(dist[i]>temp) temp=dist[i];
		}
		cout<<temp<<endl;
	}
}
	
