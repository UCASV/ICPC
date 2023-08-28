//11340 Newspaper
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    char c;
    string s;
    int N, K, M, a, acc;
    vector<char> cars;
    vector<int> cents;

    cin >> N;
    for(int i = 0; i < N; ++i){
        acc = 0;

        cin >> K;
        for(int j = 0; j < K; ++j){
            cin >> c >> a;
            cars.push_back(c);
            cents.push_back(a);
        }
        cars.push_back('\0'); //Para que las búsquedas en el vector funcionen

        cin >> M;
        getline(cin, s); //Para limpiar el \n que queda después de leer M
        for(int j = 0; j < M; ++j){
            getline(cin, s);
            for(int c = 0; c < s.length(); ++c){
                vector<char>::iterator it = find(cars.begin(),cars.end(),s[c]); //Para buscar un dato en el vector
                if(it != cars.end()){
                    acc += cents.at(it-cars.begin()); //Para obtener la posición donde se encontró el caracter
                }
            }
        }
        printf("%.2f$\n",acc/100.0); //Para que coloque exactamente 2 decimales every time

        cars.clear();
        cents.clear();
    }

    return 0;
}
