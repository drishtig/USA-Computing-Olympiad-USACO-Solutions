#include <iostream>
using namespace std;
#include <string>

int FindIndex(string alphabet, char letter){
    for (int i = 0; i < alphabet.size(); i++){
        if (alphabet[i] == letter){
            return i;
        }
    }
    return 0;

}
int main(){
    string alphabet;
    string heard;
    cin >> alphabet;
    cin >> heard; 

    int numTimes = 0;
    
    for (int i = 0; i < heard.size(); i++){
        if ((FindIndex(alphabet, heard[i]) > FindIndex(alphabet, heard[i+1])) ||  (FindIndex(alphabet, heard[i]) == FindIndex(alphabet, heard[i+1]))){
            numTimes++;
        }
    }
    cout << numTimes << endl;
}