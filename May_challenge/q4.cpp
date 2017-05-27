#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,p,k;
  cin>>n>>k>>p;
  char a[n];
  for(int i=0;i<n;i++) cin>>a[i];
  char b[p];
  int ind[n-k+1];
  for(int i=0;i<p;i++) cin>>b[i];
  int icount=0;
  for(int i=0;i<k;i++){
    if(a[i]=='1') icount++;
  }
  if(n<=k){
    for(int i=0;i<p;i++){
      if(b[i]=='?') cout<<icount<<endl;
    }
    return 0;
  }
  int maxw=icount;
  int max_index=0;
  for(int i=0;i<n-k;i++){
    if(a[k+i]=='1' && a[i]=='0') {
      icount++;
      if(icount>maxw) {
        maxw=icount;
        max_index=i+1;
      }
    }
    else if(a[k+i]=='0' && a[i]=='1'){
      icount--;
    }
  }
  int buffer=0;
  for(int i=0;i<p;i++){
    if(b[i]=='?'){
    cout<<maxw<<endl;
    }
    else if(b[i]=='!'){
      buffer--;
      int q=buffer/n;
      if(buffer<0) q--;
      buffer=buffer-(q*n);
      if(a[buffer]=='1'){
        int tempcount=0,tcount=0;
        for(int j=buffer;tempcount<k;tempcount++){
          if(a[j]=='1') tcount++;
          j++;
          j=j%n;
        }
        if(max_index==buffer-k+1){
          tempcount=0;
          maxw=tcount;
          max_index=buffer;
          for(int j=buffer;tempcount<n-k;tempcount++){
            if(a[(k+j)%n]=='1' && a[j]=='0') {
              tcount++;
              if(tcount>maxw) {
                maxw=tcount;
                max_index=j+1;
                max_index=max_index%n;
              }
            }
            else if(a[(k+j)%n]=='0' && a[j]=='1'){
              tcount--;
            }
            j++;
            j=j%n;
          }
        }
        else{
          if(tcount>=maxw) {
            maxw=tcount;
            max_index=buffer;
        }
      }


    }
  }

}
return 0;
}
