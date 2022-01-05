#include <iostream>
using namespace std;
#include <stack>


int count;


void dfs(int x, int y, int m, char **array, bool down, int numChanges, int k){
    extern int count;
    if (x < 0 || x >= m || y < 0 || y >= m || array[y][x] == 'H' || numChanges > k){
        return;
    }
    if (x == y && y == m - 1){
        count += 1;
        return;
    }
    if (down){
        dfs(x, y+1, m,array, true, numChanges, k);
        dfs(x+1, y, m,array, false, numChanges + 1, k);
    }
    else{
        dfs(x, y+1, m,array, true, numChanges + 1, k);
        dfs(x+1, y, m,array, false, numChanges, k);
    }
}
int main(){
    int n;
    int m;
    int k;
    extern int count;
    

    cin >> n;
    
    for (int t = 0; t < n; t++){
        cin >> m;
        cin >> k;
        count = 0;
        char **array;

        array = new char *[m];
        for(int i = 0; i <m; i++)
            array[i] = new char[m];

        for (int i = 0; i < m; i++){
            for (int j = 0; j < m; j++){
                cin >> array[i][j];
            }
        }
        dfs(1, 0, m,array, false, 0, k);
        dfs(0, 1, m,array, true, 0, k);
        cout << count << endl;

        
    }
}

