#include <iostream>
using namespace std;
int LessThanEqualBinSearch( int key, int data[], const int len )
{
    int min = 0;
    int max = len-1;
    // var max = data.length - 1; // Javascript, Java conversion

    while( min <= max)
    {
        int mid = min + ((max - min) / 2);

        /**/ if (data[mid] < key)  min  = mid + 1;
        else if (data[mid] > key)  max  = mid - 1;
        else   /*data[mid] = key)*/return mid    ;
    }

    if( max < 0 )
        return 0;  // key < data[0]
    else
    if( min > (len-1))
        return -1; // key >= data[len-1] // KEY_NOT_FOUND
    else
        return (min < max)
            ? min  
            : max + 1;
}
int main(){
	int a[]={1,3,3,3,4,5,6};
	cout<<LessThanEqualBinSearch(3,a,7);
}
