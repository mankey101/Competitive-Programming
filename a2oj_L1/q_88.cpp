#include <iostream>
#include <set>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  int a[n];
  for(int i=0;i<n;i++) cin>>a[i];
  int query[m];
  for(int i=0;i<m;i++) cin>>query[i];
  int dis[n];
  set<int> temp;
  for(int i=n-1;i>=0;i--){
    temp.insert(a[i]);
    dis[i]=temp.size();
  }
  int d;
  for(int i=0;i<m;i++){
    d=dis[query[i]-1];
    cout<<d<<endl;
  }

}
