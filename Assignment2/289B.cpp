#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> v;
	int n,m,k,d,ans = 0;
	bool c = true;
	cin >> n >> m >> d;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> k;
			v.push_back(k);
		}
	}
	sort(v.begin(),v.end());
	int r = v[(v.size() / 2)];
	for(int i = 0 ; i < v.size();i++){
		if(v[i] < r){
			ans += ((r - v[i])/ d);
			v[i] += ((r - v[i])/ d) * d;
		}else if(v[i] > r){
			ans += ((v[i]- r)/ d);
			v[i] -= ((v[i]- r)/ d) * d;
		}
		if(v[i] != r){
			c = false;
		}
	}
  if(c==true) cout<<ans;
  else cout<<-1;
	return 0;
}
