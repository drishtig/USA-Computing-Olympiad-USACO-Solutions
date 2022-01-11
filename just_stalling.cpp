#include <iostream>
#include <algorithm>
using namespace std;

int N;

int findNumStalls(int S[], int num){
    int numStalls = 0;
    for (int i = 0; i < N; i++){
        if (num <= S[i]){
            numStalls++;
        }
    }
    return numStalls;

}

int main(){
    int numStalls;
    cin >> N;
    int counter = -1;
    long long ans = 1;

    int C[N], S[N];

    for (int i = 0; i < N; i++){
        cin >> C[i];
    }
    for (int i = 0; i < N; i++){
        cin >> S[i];
    }

    sort(C, C+N);

    for (int i = N-1; i >= 0; i--){
        counter++;
        if (i == N){
            numStalls = findNumStalls(S, C[i]);
            cout << numStalls << endl;
        }
        else{
           numStalls = findNumStalls(S, C[i]) -  counter;
        }
        ans = ans*numStalls;

    }
    cout << ans << endl;
}