#include <iostream>
#include <climits>
using namespace std;

int contar_digitos(int n){
    int cont;
    if(n < 10) return 1;
    while(n >= 10){
        n = n / 10;
        ++cont;
    }
    return cont+1;
}
/*    
    2345
    floor(2345/10) = 234
    2345%10 = 5
   
    floor(2345/10^2) = 23
    2345%10^2 = 45
   
    floor(2345/10^3) = 2
    2345%10^2 = 345
   
    2345./10^1   = 234.5
    2345. x 10 = 23450.
   
    2345./10^2   = 23.45
    2345. x 10^2 = 234500.
   
    2345./10^3   = 2.345
    2345. x 10^3 = 2345000.
*/

int build_border(int d, int n){
    int acc = d;
    for(int i = 1; i <= n; ++i)
        acc += d*pow(10,i);
    return acc;
}
/*
2 - 3
acc = 2 + 2*10^1 + 2*10^2 + 2*10^3 = 2 + 20 + 200 + 2000 = 2222
*/

int main(){
    int n;
    cin >> n;
    if(n < 10) cout << n + 1 << "\n";
    else{
        int nd = floor(log10(n));
        int first = n/pow(10,nd);
        int border = build_border(first, nd);
        int ans = 10*nd + first - ((n >= border)?0:1) << "\n";
    }
    return 0;
}
