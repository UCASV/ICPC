//11498 Division of Nlogonia
#include <iostream>
using namespace std;

int main(void){
    int K, N, M, X, Y;
    cin >> K;
    while( K != 0 ){
        cin >> N >> M;
        for(int i = 0; i < K; i++){
            cin >> X >> Y;
            if(X == N || Y == M) cout << "divisa\n";
            else
                if(X < N)
                    if(Y < M) cout << "SO\n";
                    else cout << "NO\n";
                else
                    if(Y < M) cout << "SE\n";
                    else cout << "NE\n";
        }
        cin >> K;
    }
    
    return 0;
}