//11559 Event Planning
#include <iostream>
#include <climits>
using namespace std;

int main(void){
    bool flag;
    int N, B, H, W, p, a, total, min;

    while(cin >> N >> B >> H >> W){
        flag = false;
        min = INT_MAX;
        for(int i = 0; i < H; ++i){
            cin >> p;
            total = p*N;
            for(int i = 0; i < W; ++i){
                cin >> a;
                if(!flag && N <= a) flag = true;
            }
            if(total <= B && total < min && flag) min = total;
        }
        if(min == INT_MAX) cout << "stay home\n";
        else cout << min << "\n";
    }

    return 0;
}
