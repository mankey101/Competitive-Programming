#include <bits/stdc++.h>
using namespace std;

int NextLargestBinSearch( int key, int data[], const int len )
{
    int low  = 0;
    int high = len-1;

    while( low <= high)
    {
        // To convert to Javascript:
        // var mid = low + ((high - low) / 2) | 0;
        int mid = low + ((high - low) / 2);

        /**/ if (data[mid] < key) low  = mid + 1;
        else if (data[mid] > key) high = mid - 1;
        else return                      mid + 1;
    }

    if( high < 0 )
        return 0;   // key < data[0]
    else
    if( low > (len-1))
        return len; // key >= data[len-1]
    else
        return (low < high)
            ? low  + 1
            : high + 1;
}
int main(){
	int a[]={1,2,3,4,5};
	int f=NextLargestBinSearch(0,a,5);
	cout<<f;
}
