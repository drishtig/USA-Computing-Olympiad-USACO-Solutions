#include <iostream>
#include <string>
#include <vector>
using namespace std;

int CW = 0;
int CCW = 0;

void checkDirection(vector <char> changes){
    CW = 0;
    CCW = 0;
    for (int i = 0; i < changes.size() - 1; i++){
        if (changes[i] == 'N' && changes[i+1] == 'E'){
            CW++;
        }
        if (changes[i] == 'N' && changes[i+1] == 'W'){
            CCW++;
        }
        if (changes[i] == 'S' && changes[i+1] == 'E'){
            CCW++;
        }
        if (changes[i] == 'S' && changes[i+1] == 'W'){
            CW++;
        }
        if (changes[i] == 'E' && changes[i+1] == 'N'){
            CCW++;
        }
        if (changes[i] == 'E' && changes[i+1] == 'S'){
            CW++;
        }
        if (changes[i] == 'W' && changes[i+1] == 'N'){
            CW++;
        }
        if (changes[i] == 'W' && changes[i+1] == 'S'){
            CCW++;
        }
        
    }
    if (CW > CCW){
            cout << "CW" << endl;
    }
    else{
           cout << "CCW" << endl;
    }
}
int main(){
    int N;
    cin >> N;
    string fence;
    vector <char> changes;

    for (int i = 0; i < N; i++){
        cin >> fence;
        for (int j = 0; j < fence.size()-1; j++){
            if (fence[j] != fence[j+1]){
                changes.push_back(fence[j]);
                changes.push_back(fence[j+1]);
            }
        }
        checkDirection(changes);
        changes.clear();
    }
}