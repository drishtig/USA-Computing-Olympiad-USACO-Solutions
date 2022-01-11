#include <iostream>
#include <vector>
using namespace std;
#define MAXN 1001

int numComfortable = 0;
int N;
int counter = 0;
int cows[MAXN][MAXN];

void getNumComfortable(int x, int y){
    counter = 0;
    if (cows[x][y+1] == 1){
        counter++;
    }
    if (cows[x][y-1] == 1){
        counter++;
    }
    if (cows[x+1][y] == 1){
        counter++;
    }
    if (cows[x-1][y] == 1){
        counter++;
    }
    if (counter == 3){
        numComfortable++;
    }
    else if (numComfortable > 0 && counter > 3){
        numComfortable--;
    }
}

int main() {
    int x, y;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> x >> y;
        cows[x][y] = 1;

        if (i >= 3){
            if (cows[x][y+1] == 1){
                getNumComfortable(x, y+1);
            }
            if (cows[x][y-1] == 1){
                getNumComfortable(x, y-1);
            }
            if (cows[x+1][y] == 1){
                getNumComfortable(x+1, y);
            }
            if (cows[x-1][y] == 1){
                getNumComfortable(x-1, y);
            }
            getNumComfortable(x, y);
            cout << numComfortable << endl;
        }
        else{
            cout << 0 << endl;
        }
    }  
}