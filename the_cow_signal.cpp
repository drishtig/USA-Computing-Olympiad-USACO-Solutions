#include <iostream>
using namespace std;
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

int main(){
    ifstream in_stream;
    ofstream out_stream;

    in_stream.open("cowsignal.in");
    out_stream.open("cowsignal.out");

    int M, N, K;
    string line;
    string line2 = "";

    in_stream >> M >> N >> K;
    for (int t = 0; t < M; t++){
        line2 = "";
        in_stream >> line;
        if (t > 0){
            out_stream << endl;
        }
        for (int i = 0; i < line.size(); i++){
            for (int j = 0; j < K; j++){
                out_stream << line[i];
                line2 = line2 + line[i];
            }
        }
        for (int i = 0; i < K-1; i++){
            out_stream << endl;
            out_stream << line2;
        }
    }
    

}

