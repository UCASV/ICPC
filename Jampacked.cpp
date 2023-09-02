#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long n,k;
    cin >> n >> k;
    if(n < k) printf("%lld\n",n);
    else
		if(n % k == 0) printf("%lld\n",k);
        else printf("%lld\n",n/(n/k+1));
	
    return 0;
}