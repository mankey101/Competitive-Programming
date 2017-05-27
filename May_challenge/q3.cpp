#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  for(int m=0;m<t;m++){
    int n;
    cin>>n;
    int l=2*n;
    int b[l];
    int a[n];
    for(int i=0;i<l;i++) cin>>b[i];
    sort(b,b+l);
    for(int i=n;i<l;i++){
      a[i-n]=b[i];
    }
    sort(a,a+n);
    cout<<a[n/2]<<endl;
    for(int i=0;i<n;i++){
      cout<<b[i]<<" "<<b[l-i-1]<<" ";
    }
    cout<<endl;
  }
}
