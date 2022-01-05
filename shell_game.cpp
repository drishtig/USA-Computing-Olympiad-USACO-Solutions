sh#include <iostream>
using namespace std;
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

int main(){
    ifstream in_stream;
    ofstream out_stream;

    in_stream.open("shell.in");
    out_stream.open("shell.out");

    map <int, int> shellGame;
    vector <int> locations;
    vector <int> guesses;
    int N;
    int one;
    int two;
    int three;
    int loc1;
    int loc2;
    int loc3;
    int loc4;
    int loc5;
    int loc6;
    int guess;
    int score = 0;
    int score2 = 0;
    int score3 = 0;
    int counter = 0;
    in_stream >> N;

    //Case 1
    shellGame.emplace(1, 1);
    shellGame.emplace(2, 0);
    shellGame.emplace(3, 0);
    
    for (int i = 0; i < N; i++){
        in_stream >> loc1;
        in_stream >> loc2;
        locations.push_back(loc1);
        locations.push_back(loc2);
        int temp = shellGame.at(loc1);
        shellGame.at(loc1) = shellGame.at(loc2);
        shellGame.at(loc2) = temp;
        
        in_stream >> guess;
        guesses.push_back(guess);

        if (shellGame.at(guess) == 1){
            score++;
        }
    }

    //Case 2
    shellGame.at(1) = 0;
    shellGame.at(2) = 1;
    shellGame.at(3) = 0;
    counter = 0;

    for (int i = 0; i < N; i++){
        loc1 = locations[counter];
        loc2 = locations[counter+1];
        int temp = shellGame.at(loc1);
        shellGame.at(loc1) = shellGame.at(loc2);
        shellGame.at(loc2) = temp;
        guess = guesses[i];

        if (shellGame.at(guess) == 1){
            score2++;
        }
        counter = counter +2;
    }

    //Case 3;
    shellGame.at(1) = 0;
    shellGame.at(2) = 0;
    shellGame.at(3) = 1;
    counter = 0;
    
    for (int i = 0; i < N; i++){
        loc1 = locations[counter];
        loc2 = locations[counter+1];
        int temp = shellGame.at(loc1);
        shellGame.at(loc1) = shellGame.at(loc2);
        shellGame.at(loc2) = temp;
        guess = guesses[i];

        if (shellGame.at(guess) == 1){
            score3++;
        }
        counter= counter+2;
    }

   if ((score >= score2) && (score >= score3)){
        out_stream << score << endl;
    }
    else if ((score2 >= score) && (score2 >= score3)){
        out_stream << score2 << endl;
    }
    else{
        out_stream << score3 << endl;
    }

}