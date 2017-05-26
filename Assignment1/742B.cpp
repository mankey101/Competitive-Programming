#include <bits/stdc++.h>
using namespace std;
int myXOR(int x, int y);
int binarySearch(int arr[], int l, int r, int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;
 
        // If the element is present at the middle itself
        if (arr[mid] == x)  return mid;
 
        // If element is smaller than mid, then it can only be present
        // in left subarray
        if (arr[mid] > x) return binarySearch(arr, l, mid-1, x);
 
        // Else the element can only be present in right subarray
        return binarySearch(arr, mid+1, r, x);
   }
 
   // We reh here when element is not present in array
  return -1;
}
int main(){
	int n,x;
	cin>>n>>x;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	long long int count=0;
	long long int countt[n];
	for(int i=0;i<n;i++){
		long long int count=1;
		int tempi=i;
		while(i<n-1 && a[i+1]==a[i]){
			count++;
			i++;
		}
		for(int j=tempi;j<=i;j++) countt[j]=count;
	}
	long long int count2=0;				
	for(int i=0;i<n;i++){
		long long int tempcount=0;
		int t=myXOR(a[i],x);
		int found=binarySearch(a,0,n,t);
		if(found!=-1){
			tempcount=countt[found];
			if (a[found]==a[i] && countt[found]==1) tempcount=0;
			else if(a[found]==a[i] && countt[found]>1) tempcount=countt[found]-1;   
			long long int temp=1;
			while(i<n-1 && a[i]==a[i+1] && tempcount!=0){
				temp++;
				i++;
			}
			count2=count2+tempcount*temp;
		}
	}
cout<<count2/2;
return 0;
}
int myXOR(int x, int y)
{
    int res = 0; // Initialize result
     
    // Assuming 64-bit Integer 
    for (int i = 63; i >= 0; i--)                     
    {
       // Find current bits in x and y
       bool b1 = x & (1 << i);
       bool b2 = y & (1 << i);
        
        // If both are 1 then 0 else xor is same as OR
        bool xoredBit = (b1 & b2) ? 0 : (b1 | b2);          
 
        // Update result
        res <<= 1;
        res |= xoredBit;
    }
    return res;
}
