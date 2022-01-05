#include <iostream>
using namespace std;
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>

int main() {
    ifstream in_stream;
    ofstream out_stream;

    in_stream.open("paint.in");
    out_stream.open("paint.out");
    vector <int> numbers;

    int a;
    int b;
    int c;
    int d;
    int total;
    
    in_stream >> a;
    in_stream >> b;
    in_stream >> c;
    in_stream >> d;

    numbers.push_back(a);
    numbers.push_back(b);
    numbers.push_back(c);
    numbers.push_back(d);

    sort(numbers.begin(), numbers.end());
    total = numbers[3] - numbers[0];
    
    if ((a==c) && (b==d)){
        out_stream << b-a << endl;
    }
    else if ((c > b) || (d < a)){
        out_stream << abs(b-a) + abs(d-c) << endl;
    }
    else{
        out_stream << total << endl;
    }


}