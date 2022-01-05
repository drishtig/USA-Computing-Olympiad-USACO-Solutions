#include <iostream>
using namespace std;
#include <fstream>

class Rectangle{
    public:
    int x1;
    int x2;
    int y1;
    int y2;
    Rectangle(){
        x1 = 0;
        x2 = 0;
        y1 = 0;
        y2 = 0;
    }

};

int totalArea(Rectangle r){
    int area = (abs(r.x2 -r.x1)* abs(r.y2-r.y1));
    return area;
}

Rectangle intersection(Rectangle x, Rectangle y){
    Rectangle r;
    r.x1 = max(x.x1, y.x1);
    r.y1 = max(x.y1, y.y1);
    r.x2 = min(x.x2, y.x2);
    r.y2 = min(x.y2,y.y2);

    if ((r.x1 > r.x2) || (r.y1 > r.y2)){
        r.x1 = 0;
        r.y1 = 0;
        r.x2 = 0;
        r.y2 = 0;
    }

    return r;
}

int main(){
    Rectangle b1;
    Rectangle b2;
    Rectangle truck;

    ifstream in_stream;
    ofstream out_stream;

    in_stream.open("billboard.in");
    out_stream.open("billboard.out");

    int tArea = 0;
    int inter = 0;

    in_stream >> b1.x1;
    in_stream >> b1.y1;
    in_stream >> b1.x2;
    in_stream >> b1.y2;
    in_stream >> b2.x1;
    in_stream >> b2.y1;
    in_stream >> b2.x2;
    in_stream >> b2.y2;
    in_stream >> truck.x1;
    in_stream >> truck.y1;
    in_stream >> truck.x2;
    in_stream >> truck.y2;

    tArea = totalArea(b1) + totalArea(b2);
    Rectangle z = intersection(b1, truck);
    Rectangle w = intersection(b2, truck);
    inter = totalArea(z) + totalArea(w);
    out_stream << tArea - inter << endl;

}