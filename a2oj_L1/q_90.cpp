#include <iostream>
#include <algorithm>
using namespace std;
void merge(long long int *a,int low, int high, int mid );
void mergesort(long long int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,high,mid);
    }
    return;
}
void merge(long long int *a, int low, int high, int mid)
{
    int i, j, k;
    long long int c[100000];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        a[i] = c[i];
    }
}
int main(){
  int n;
  cin>>n;
  long long int v[n];
    long long int sum[n],sum1[n];
  for(int i=0;i<n;i++) {
    cin>>v[i];
    if(i==0) sum[i]=v[i];
    else sum[i]=sum[i-1]+v[i];
  }
  mergesort(v,0,n-1);
  for(int i=0;i<n;i++){
    if(i==0) sum1[i]=v[i];
    else sum1[i]=sum1[i-1]+v[i];
  }

  int m;
  cin>>m;
  int type[m];
  int queryl[m];
  int queryr[m];

  for(int i=0;i<m;i++) {
    cin>>type[i]>>queryl[i]>>queryr[i];
  }
  for(int i=0;i<m;i++){
    if(type[i]==1){
      if(queryl[i]<2) cout<<sum[queryr[i]-1]<<endl;
      else cout<<sum[queryr[i]-1]-sum[queryl[i]-2]<<endl;
    }
    else if(type[i]==2){
      if(queryl[i]<2) cout<<sum1[queryr[i]-1]<<endl;
      else cout<<sum1[queryr[i]-1]-sum1[queryl[i]-2]<<endl;
    }

  }


}
