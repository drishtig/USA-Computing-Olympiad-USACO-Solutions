#include <iostream>
#include <map>
using namespace std;

int main(){
    map <int, int> flowers;
    int N;
    int f;
    float average = 0;
    int counter = 0;
    int numCombinations = 0;
    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> f;
        flowers.emplace(i+1, f);
    }
    for (int i = 1; i <= N; i++){
        for (int j = i; j <= N; j++){
	        average = 0;
        for (int z = i; z <= j; z++){
		    average = average + flowers.at(z);
            if (z == j){

                if (i == j){
                    average = average/1;
                }
                else{
                    average = (average / ((j-i)+1));
                }
            }
	    }
    	for (int z = i; z <= j; z++){
		    if (flowers.at(z) == average){
				counter++;
				break;
		    }
		}
    }
    }
    
    cout << counter << endl;
}

