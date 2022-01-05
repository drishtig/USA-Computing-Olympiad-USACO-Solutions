#include <iostream>
using namespace std;
#include <string>
#include <map>

int main(){
    long long int N;
    cin >> N;
    string s;
    cin >> s;

    map <char, int> m;
    long long int count = 0;


    for (int windowSize = 3; windowSize <= N; windowSize++){
        m.clear();
        m.emplace('G', 0);
        m.emplace('H', 0);

        for (int j = 0; j < windowSize; j++){
            m.at(s[j]) = m.at(s[j]) + 1;
        }
        for (int j = 0; j <= N - windowSize; j++){
            char start = s[j];
            if (m.at('H') == 1 || m.at('G') == 1){
                count++;
            }
            m.at(start) = m.at(start) - 1;
            if (j + windowSize < N){
                m.at(s[j+windowSize]) = m.at(s[j+windowSize]) + 1;
            }
        }
        
    }
    cout << count << endl;

}
