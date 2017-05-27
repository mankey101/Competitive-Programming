#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,k,p;
  cin>>n>>k>>p;
  bool a[n];
  for(int i=0;i<n;i++) cin>>a[i];
  char b[p];
  for(int i=0;i<p;i++) cin>>b[i];
    //input complete
    if(n<=k){
      int maxi=0;
      for(int i=0;i<n;i++) maxi=maxi+a[i];
      for(int i=0;i<p;i++){
        if(b[i]=='?') cout<<maxi<<endl;
        }
    return 0;
    }
  list<int> store;
  int set=0,set_p;
  for(int i=0;i<=n-k;i++){
    if(i==0){
      for(int j=i;j<k;j++){
        set=set+a[j];
      }
    }
      else set=set_p-a[i-1]+a[i+k-1];
      store.push_back(set);
      set_p=set;
  }
  int maxi=*max_element(store.begin(),store.end());
  int index = distance(store.begin(),max_element(store.begin(),store.end()));
  int end=n-1;
  int start=k-1;

  for(int i=0;i<p;i++){
    if(b[i]=='?') cout<<maxi<<endl;
    else if(b[i]=='!'){
      int front=store.front();
      store.pop_back();
      store.push_front(front+a[end]-a[start]);
        if(index==n-k){
          maxi=*max_element(store.begin(),store.end());
          index = distance(store.begin(),max_element(store.begin(),store.end()));
        }
        else
  			{
  				if(store.front() >= maxi)
  				{
  					maxi = store.front();
  					index = 0;
  				}
  				else index++;
  			}
        if(end==0) end=n-1;
        else end--;
        if(start==0) start=n-1;
        else start--;
    }

    }
}
