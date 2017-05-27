#include <iostream>
#include <algorithm>
using namespace std;


long long int modulus_user(long int a){
  if(a>=0) return a;
  else return -a;
}
int main(){
  int n;
  cin>>n;
  long long int a[n];
  for(int i=0;i<n;i++) cin>>a[i];
  sort(a,a+n);
  long long int steps=0;
  for(int i=0;i<n;i++){
    steps+=modulus_user(a[i]-(i+1));
  }
  cout<<steps;
}
