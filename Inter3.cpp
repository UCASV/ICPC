//10855 Rotated squares
#include <iostream>

using namespace std;

//Hay que conocer manejo de matrices en términos de operaciones básicas y uso respectivo de punteros
//para envío y manipulación por valor y por referencia

void creation(char ***M, int size){
    *M = (char**) malloc(sizeof(char*)*size);
        for(int i = 0; i < size; ++i)
            (*M)[i] = (char*) malloc(sizeof(char)*size);
}

void read_matrix(char ***M, int size){
    char c;
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size; ++j){
            cin >> (*M)[i][j];
        }
    }
}

void liberation(char** M, int size){
    for(int i = 0; i < size; ++i)
        free(M[i]);
    free(M);
}

//O(n^4)
int check(char **M, int N, char **small, int size_small){
    bool flag = true;
    int cont = 0;
    for(int i = 0; i < N-(size_small-1); ++i){
        for(int j = 0; j < N-(size_small-1); ++j){
            flag = true;
            for(int p = 0; p < size_small; ++p){
                for(int q = 0; q < size_small; ++q){
                    if(small[p][q] != M[i+p][j+q]){
                        flag = false;
                        break;
                    }
                }
                if(!flag) break;
            }
            if(flag) cont++;
        }
    }
    
    return cont;
}

void rotate(char ***m, int size){ //Rotate 90° clockwise
    char** temp;
    creation(&temp, size);
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size; ++j){
            temp[j][size-(i+1)] = (*m)[i][j]; //fila de arriba a abajo se hace columna de derecha a izquierda
        }
    }
    liberation(*m, size);
    *m = temp;
}

int main(void){
    int size_big, size_small, cont, R[4];
    char **big, **small;
    
    cin >> size_big >> size_small;
    while( size_big != 0 && size_small != 0){
        creation(&big, size_big);
        creation(&small, size_small);
        read_matrix(&big, size_big);
        read_matrix(&small, size_small);

        R[0] = check(big, size_big, small, size_small);
        rotate(&small,size_small);
        R[1] = check(big, size_big, small, size_small);
        rotate(&small, size_small);
        R[2] = check(big, size_big, small, size_small);
        rotate(&small, size_small);
        R[3] = check(big, size_big, small, size_small);

        cout << R[0] << " " << R[1] << " " << R[2] << " " << R[3] << "\n";

        liberation(big, size_big);
        liberation(small, size_small);

        cin >> size_big >> size_small;
    }

    return 0;
}
