#include <iostream>
using namespace std;
#include <fstream>
#include <cmath>

int SmallerAB(int a, int b){
    if (a < b){
        return a;
    }
    else{
        return b;
    }
    return 0;
}
int SmallerXY(int x, int y){
    if (x < y){
        return x;
    }
    else{
        return y;
    }
    return 0;
}
int LargerAB(int a, int b){
    if (a < b){
        return b;
    }
    else{
        return a;
    }
    return 0;
}
int LargerXY(int x, int y){
    if (x < y){
        return y;
    }
    else{
        return x;
    }
    return 0;
}
int main(){

    ifstream in_stream;
    ofstream out_stream;
    in_stream.open("teleport.in");
    out_stream.open("teleport.out");

    int a;
    int b;
    int x;
    int y;

    in_stream >> a;
    in_stream >> b;
    in_stream >> x;
    in_stream >> y;

    int maxDistance = abs(b - a);
    int d1;
    int d2;

    d1 = abs(SmallerAB(a,b) - SmallerXY(x,y));
    d2 = abs(LargerAB(a,b) - LargerXY(x,y));

    int minDistance = abs(d1 + d2);

    if (maxDistance < minDistance){
        out_stream << maxDistance;
    }
    else{
        out_stream << minDistance;
    }

}