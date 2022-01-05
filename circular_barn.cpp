#include <iostream>
using namespace std;
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>

int main(){
    ifstream in_stream;
    ofstream out_stream;

    in_stream.open("cbarn.in");
    out_stream.open("cbarn.out");

    int N; 
    int totalCows = 0;
    int minDistance = 0;
    in_stream >> N;
    vector <int> numCows(N);
    vector <int> minDistances;

    int counter = 0;
    int door = 0;
    int cow = 0;

    for (int i = 0; i < N; i++){
        in_stream >> numCows[i];
        totalCows = totalCows + numCows[i];
    }

for (int j = 0; j < N; j++){
    minDistance = 0;
    counter = 0;
    for (int i = 0; i < N; i++){
        if (i > 0){
            minDistance = minDistance + numCows[i] + counter*(numCows[i]);
            counter++;
        }
    }
    minDistances.push_back(minDistance); 

    cow = numCows[0];
    numCows.erase(numCows.begin());
    numCows.push_back(cow);

}

    minDistance = minDistances[0];

    for (int i = 0; i < N; i++){
        if (minDistances[i] <= minDistance){
            minDistance = minDistances[i];
        }
    }

    out_stream << minDistance << endl;

    





}