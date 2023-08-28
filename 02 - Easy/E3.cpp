//11799 Horror Dash
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int T, N, c;
    vector<int> speeds;

    cin >> T;
    for(int i = 0; i < T; ++i){
        cin >> N;
        for(int j = 0; j < N; j++){
            cin >> c;
            speeds.push_back(c);
        }

        sort(speeds.begin(),speeds.end());

        cout << "Case " << i+1 << ": " << speeds.at(N-1) << "\n";
        speeds.clear();
    }

    return 0;
}
