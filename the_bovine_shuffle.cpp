#include <iostream>
using namespace std;
#include <map>
#include <fstream>

int main(){
        ifstream in_stream;
        ofstream out_stream;

        in_stream.open("shuffle.in");
        out_stream.open("shuffle.out");


        int N;
        int loc;
        string ID;
        in_stream >> N;
        int locations[N];
        string IDs[N];
        string temp[N];
        
        map <int, int> shuffle;

        for (int i = 1; i < N+1; i++){
                in_stream >> loc;
                shuffle.emplace(loc, i);
        }
        for (int i = 0; i < N; i++){
                in_stream >> ID;
                IDs[i] = ID;
                locations[i] = i+1;
        }
        for (int i = 0; i < 3; i++){
                for (int j = 1; j < N+1; j++){
                        loc = shuffle.at(j);
                        temp[loc-1] = IDs[j-1];

                }
                for (int j = 0; j < N; j++){
                        IDs[j] = temp[j];
                }
        }
        
        for (int i = 0; i < N; i++){
                out_stream << IDs[i] << endl;

        }
}