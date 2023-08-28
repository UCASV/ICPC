//11727  Cost Cutting
#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int T, N[3];

    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> N[0] >> N[1] >> N[2];
        sort(N,N+3);

        cout << "Case " << i+1 << ": " << N[1] << "\n";
    }
    
    return 0;
}