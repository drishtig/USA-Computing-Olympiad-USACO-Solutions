#include <iostream>
using namespace std;
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

int main(){
        ifstream in_stream;
        ofstream out_stream;

        in_stream.open("blocks.in");
        out_stream.open("blocks.out");

        int N;
        in_stream >> N;
        string word1;
        string word2;
        int num1 = 0;
        int num2 = 0;
        int maxNum = 0;
        int total = 0;

        string words[N];
        char alphabet [26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        int blocks[26];

        for (int i = 0; i < 26; i++){
            blocks[i] = 0;
        }

        for (int i = 0; i < N; i++){
            in_stream >> word1;
            in_stream >> word2;
            for (int j = 0; j < 26; j++){
                num1 = 0;
                num2 = 0;
                for(int a = 0; a < word1.size(); a++){
                    if (word1[a] == alphabet[j]){
                        num1++;
                    }
                }
                for(int a = 0; a < word2.size(); a++){
                    if (word2[a] == alphabet[j]){
                        num2++;
                    }
                }
                maxNum = max(num1, num2);

                blocks[j] = maxNum + blocks[j];
            }
            
        }
        for (int i = 0; i < 26; i++){
            out_stream << blocks[i] << endl;
        }
        out_stream.close();
}

