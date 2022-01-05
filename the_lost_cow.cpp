#include <iostream>
using namespace std;
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

int main(){
    ifstream in_stream;
    ofstream out_stream;

    in_stream.open("lostcow.in");
    out_stream.open("lostcow.out");

    int x, y;
    int distance = 0;
    int num = 1;
    
    int end = 0;
    int sum = 0;
    int c = 0;
    int d = 0;
    int counter = 0;
    vector <int> distances;
    bool keep_going = false;
    in_stream >> x >> y;
    int a = x;

    while (!keep_going){
        end = x + num;
        distance = distance + abs(a - end);
        num = -1*(num*2);
        a = end;
        counter++;
        keep_going = ((y >= x && y <= end) || (y >= end && y <= x));
    }

    distance = distance - abs(end - y);
    out_stream << distance << endl;
}