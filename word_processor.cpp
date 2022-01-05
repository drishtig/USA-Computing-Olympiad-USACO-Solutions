#include <iostream>
using namespace std;
#include <fstream>
#include <string>

int main(){
    int N;
    int K;
    string word;
    int size = 0;
    ifstream in_stream;
    ofstream out_stream;
    in_stream.open("word.in");
    out_stream.open("word.out");
    bool keep_going = true;
    int counter = 0;
    in_stream >> N;
    in_stream >> K;
    string line;
    while (counter < N){
        in_stream >> word;
        if (word.length() + size <= K){
            size = word.length() + size;
            if (size == word.length()){
                out_stream << word;
            }
            else{
                out_stream << " " << word;
            }
            
        }
        else{
            size = 0;
            out_stream << endl;
            if (word.length() + size <= K){
                size = word.length();
                out_stream << word;
            }
        }
        counter++;
    }
    
}

