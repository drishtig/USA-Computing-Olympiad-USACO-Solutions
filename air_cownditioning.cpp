#include <iostream>
using namespace std;

int minOps (int arr[], int size){
    int ans = abs(arr[0]);

    for (int i = 1; i < size; i++){
        //current = positive or current = previous
        if (arr[i] == 0 || arr[i] == arr[i-1]){
            continue;
        }
        if (arr[i-1] == 0 && arr[i] != 0){
            ans = ans + abs(arr[i]);
        }
        
        else if ((arr[i-1] < 0 && arr[i] > 0) || (arr[i-1] > 0 && arr[i] < 0)){
            ans = ans + abs(arr[i]);
        }
        else if (arr[i-1] < 0 && arr[i] < 0){
            if (arr[i] < arr[i -1]){
                ans = ans + abs(arr[i] - arr[i-1]);
            }
            else{
                continue;
            }
        }
        else{
            if (arr[i] > arr[i-1]){
                ans = ans + abs(arr[i] - arr[i-1]);
            }
            else{
                continue;
            }
        }
    }

    return ans;


}

int main() {
    int N;
    cin >> N;
    int P[N];
    int T[N];
    int D[N];

    for (int i = 0; i < N; i++){
        cin >> P[i];
    }
    for (int i = 0; i < N; i++){
        cin >> T[i];
    }
    for (int i = 0; i < N; i++){
        D[i] = (P[i] - T[i]);
    }

    cout << minOps(D, N) << endl;

}
