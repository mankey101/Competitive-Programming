// C++ program to print print all primes smaller than
// n using segmented sieve
#include <bits/stdc++.h>
using namespace std;
int primes[80000];
int t=0;
// This functions finds all primes smaller than 'limit'
// using simple sieve of eratosthenes. It also stores
// found primes in vector prime[]
void simpleSieve(int limit)
{
    // Create a boolean array "mark[0..n-1]" and initialize
    // all entries of it as true. A value in mark[p] will
    // finally be false if 'p' is Not a prime, else true.
    bool mark[limit+1];
    memset(mark, true, sizeof(mark));

    for (int p=2; p*p<limit; p++)
    {
        // If p is not changed, then it is a prime
        if (mark[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<limit; i+=p)
                mark[i] = false;
        }
    }

    // Print all prime numbers and store them in prime
    for (int p=2; p<limit; p++)
    {
        if (mark[p] == true)
        {
            primes[t++]=p;
        }
    }
}

// Prints all prime numbers smaller than 'n'
void segmentedSieve(int n)
{
    // Compute all primes smaller than or equal
    // to square root of n using simple sieve
    int limit = floor(sqrt(n))+1;
    simpleSieve(limit);

    // Divide the range [0..n-1] in different segments
    // We have chosen segment size as sqrt(n).
    int low  = limit;
    int high = 2*limit;

    // While all segments of range [0..n-1] are not processed,
    // process one segment at a time
    while (low < n)
    {
        // To mark primes in current range. A value in mark[i]
        // will finally be false if 'i-low' is Not a prime,
        // else true.
        bool mark[limit+1];
        memset(mark, true, sizeof(mark));

        // Use the found primes by simpleSieve() to find
        // primes in current range
        for (int i = 0; i < t; i++)
        {
            // Find the minimum number in [low..high] that is
            // a multiple of prime[i] (divisible by prime[i])
            // For example, if low is 31 and prime[i] is 3,
            // we start with 33.
            int loLim = floor(low/primes[i]) * primes[i];
            if (loLim < low)
                loLim += primes[i];

            /*  Mark multiples of prime[i] in [low..high]:
                We are marking j - low for j, i.e. each number
                in range [low, high] is mapped to [0, high-low]
                so if range is [50, 100]  marking 50 corresponds
                to marking 0, marking 51 corresponds to 1 and
                so on. In this way we need to allocate space only
                for range  */
            for (int j=loLim; j<high; j+=primes[i])
                mark[j-low] = false;
        }

        // Numbers which are not marked as false are prime
        for (int i = low; i<high; i++)
            if (mark[i - low] == true)
                //cout << i << "  ";
		primes[t++]=i;

        // Update low and high for next segment
        low  = low + limit;
        high = high + limit;
        if (high >= n) high = n;
    }
}
int binserl(int b,int e,int key){
	e--;
	while(b<e){
		int mid=b+(e-b)/2;
		if(primes[mid]<key) b=mid+1;
		else e=mid;
	}
	return b;
}
int binseru(int b,int e,int key){
	e--;
	while(b<e){
		int mid=b+(e-b+1)/2;
		if(primes[mid]>key) e=mid-1;
		else b=mid;
	}
	return b;
}

// Driver program to test above function
int main()
{
	ios::sync_with_stdio(false);
	int n = 1000000;
	segmentedSieve(n);
	int ab[n+1];
	ab[1]=0;
	ab[2]=1;
	ab[3]=1;
	cout<<"kya";
	for(int i=4;i<=100;i++){
		int ti=0;
		int count=0;
		while(primes[ti]<=i){
			int temp=primes[ti];
			while(i%temp==0){
				count++;
				temp=temp*primes[ti];	
			}
			ti++;
		}
		ab[i]=count;
	}
	for(int i=1;i<100;i++)  cout<<ab[i]<<endl;
	
	int N,q;
	cin>>N;
	int a[N];
	for(int i=0;i<N;i++) cin>>a[i];
	cin>>q;
	for(int i=0;i<q;i++){
		int l,r,x,y;
		cin>>l>>r>>x>>y;
		int result=0;
		int init=binserl(0,t,x);
		int fin=binseru(0,t,y);
		for(int j=l-1;j<r;j++){
			int number=a[j];
			int exponent=0;
			for(int k=init;k<=fin;k++){
				if(a[j]<primes[k]) break;
				while(number%primes[k]==0){
					exponent++;
					number=number/primes[k];
				}
			}

		result+=exponent;
		}
		cout<<result<<endl;
	}
	return 0;
}
