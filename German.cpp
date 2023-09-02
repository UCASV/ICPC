#include <iostream>
#include <cmath>
using namespace std;

int build_border(int d, int e){
    int acc = d;
    for(int i = 1; i <= e; ++i)
        acc += d*pow(10,i);
    return acc;
}

int main() {
    int n;
    cin >> n;
    if(n < 10) cout << n+1 << "\n";
    else{
        int nd = log10(n);
        int first = n / pow(10,nd);
        int border = build_border(first,nd);
        cout << 10*nd + first - ((n>=border)?0:1) << "\n";
    }
    
    return 0;
}