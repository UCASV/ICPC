#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

//The trick is to remove from the pads vector all the occupied ones

int main(){
    int n, x, q, i, temp;
    cin >> n;
    int frogs[n];
    vector<int> pads(1200000);
    
    iota(pads.begin(),pads.end(),1);

    for(int frog = 0; frog < n; ++frog){
        cin >> x;
        frogs[frog] = x;
        remove(pads.begin(),pads.end(),x);
    }

    cin >> q;
    for(int jump = 0; jump < q; ++jump){
        cin >> i;
        temp = frogs[i-1];

        auto lambda = [temp](int x) { return temp < x; };
        auto iterator = std::find_if(pads.begin(), pads.end(), lambda);

        frogs[i-1] = pads.at(iterator-pads.begin());
        pads.at(iterator-pads.begin()) = temp;
        
        cout << frogs[i-1] << "\n";
    }

    return 0;
}
