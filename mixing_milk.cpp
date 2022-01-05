#include <iostream>
using namespace std;
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

int main(){
    int difference;
    int i;
    int j;
    ifstream in_stream;
    ofstream out_stream;

    in_stream.open("mixmilk.in");
    out_stream.open("mixmilk.out");

    int C[3];
    int M[3];

    for (i = 0; i < 3; i++){
        in_stream >> C[i] >> M[i];
    }

    for (i = 0; i < 33; i++){
        j = 0;
        for (j = 0; j < 3; j++){
                difference = C[j+1] - M[j+1];
                if (j == 2){
                    difference = C[0] - M[0];
                    if (difference >= M[2]){
                        M[0] = M[0] + M[2];
                        M[2] = 0;

                    }
                    else{
                        M[0] = M[0] + difference;
                        M[2] = M[2] - difference;
                    }
                }
                else{
                    if (difference >= M[j]){
                        M[j+1] = M[j+1] + M[j];
                        M[j] = 0;
                    }
                    else{
                        M[j+1] = M[j+1] + difference;
                        M[j] = M[j] - difference;
                    }
                }
            //}
        }   
    }

    difference = C[1] - M[1];
    if (difference >= M[0]){
        M[1] = M[1] + M[0];
        M[0] = 0;
    }
    else{
        M[1] = M[1] + difference;
        M[0] = M[0] - difference;
    }

    for (i = 0; i < 3; i++){
        out_stream << M[i] << endl;;
    }

}
