#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int n;
  cin>>n;
  int dl;
  int a[3];
  for(int i=0;i<3;i++) cin>>a[i];
  sort(a,a+3);
  int sum=n;
  int i=sum/a[0];
  int j=sum/a[1];
  while(sum>=0){
    for(int k=i;k>=0;k--){
      for(int l=0;l<=j;l++){
        if(k*a[0]+l*a[1]>sum) break;
        else if(k*a[0]+l*a[1]==sum && sum!=0){
          int temp=0,temp2=0;
          for(int alf=i;alf>k;alf--){
            if(sum%(alf*a[0])==a[2]){
              temp2=sum/(alf*a[0]);
              if(alf+temp2>k+l) { k=alf; l=0; temp=1; }
            }
          }
          if(temp==0) cout<<"yo"<<k+l+(n-sum)/a[2];
          if(temp==1) cout<<k+l+temp2;
          cout<<endl<<k<<" "<<l<<endl;
          return 0;
        }
        else if(sum==0){
          if(n%a[2]==0) cout<<n/a[2];
          return 0;
        }
      }
    }
    sum=sum-a[2];
  }


}
