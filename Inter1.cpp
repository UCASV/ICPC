//10038 Jolly Jumpers
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    bool flag;
    int n, c;
    vector<int> nums;
    vector<int> diffs;

    while(cin >> n){
        flag = true;
        for(int i = 0; i < n; ++i){
            cin >> c;
            nums.push_back(c);
        }

        for(int i = 0; i < n-1; ++i){
            diffs.push_back(abs(nums.at(i)-nums.at(i+1)));
        }
        
        sort(diffs.begin(),diffs.end());
        for(int i = 1; i < n; ++i){
            if(!binary_search(diffs.begin(),diffs.end(), i)){
                flag = false;
                break;
            }
        }

        if(flag) cout << "Jolly\n";
        else cout << "Not jolly\n";

        nums.clear();
        diffs.clear();
    }

    return 0;
}
