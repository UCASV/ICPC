//11172 Relational Operators
#include <iostream>
using namespace std;

int main(void){
    int t, a, b;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> a >> b;
        if(a < b) cout << "<\n";
        else if(a > b) cout << ">\n";
             else cout << "=\n";
    }

    return 0;
}