//10114 Loansome Car Buyer
#include <iostream>
#include <vector>
using namespace std;

int main(void){

    int nmonths, records, n;
    float downp, monthp, loan, deprec, IV, f;
    vector<int> months;
    vector<float> deprecs;

    cin >> nmonths >> downp >> loan >> records;
    while(nmonths >= 0){
        monthp = loan/nmonths;
        IV = downp + loan;
        
        for(int r = 0; r < records; r++){
            cin >> n >> f;
            months.push_back(n);
            deprecs.push_back(f);
        }

        int r = 0;
        for(int m = 0; m <= nmonths; m++){
            if(m != 0) loan -= monthp;
            if(r < records && months.at(r) == m){
                deprec = deprecs.at(r);
                r++;
            }
            IV *= (1.0-deprec);
            if(loan < IV){
                cout << m << " month" << ((m==1)?"":"s") << "\n";
                break;
            }
        }
        months.clear();
        deprecs.clear();

        cin >> nmonths >> downp >> loan >> records;
    }

    return 0;
}
