#include <iostream>
using namespace std;
#include <fstream>
#include <cmath>

struct Object{
    int row;
    int column;
    Object(){
        row = 1;
        column = 1;
    }
};
int main(){
    Object barn;
    Object rock;
    Object lake;
    char c;
    int cows;
    int row = 1;
    int column = 0;
    bool keep_going = true;
    ifstream in_stream;
    ofstream out_stream;
    in_stream.open("buckets.in");
    out_stream.open("buckets.out");

    while (keep_going){
        in_stream >> c;
        column++;
        if (c == 'B'){
            barn.row = row;
            barn.column = column;
        }
        if (c == 'R'){
            rock.row = row;
            rock.column = column;
        }
        if (c == 'L'){
            lake.row = row;
            lake.column = column;
        }
        if (row == 10 && column == 10){
            keep_going = false;
        }
        if (column == 10){
            column = 0;
            row++;
        }
        
        
    }
    bool columnSame = (lake.row < rock.row && barn.row > rock.row) || (barn.row < rock.row && lake.row > rock.row);
    bool rowSame = (lake.column < rock.column && barn.column > rock.column) || (barn.column < rock.column && lake.column > rock.column);

    if (((barn.row == rock.row) && (barn.row == lake.row) && (rock.row == lake.row)) && rowSame) {
        cows = abs(barn.row - lake.row) + abs(barn.column - lake.column) - 1 + 2;
    }
       
    else if (((barn.column == rock.column) && (barn.column == lake.column) && (rock.column == lake.column)) && columnSame) {
        cows = abs(barn.row - lake.row) + abs(barn.column - lake.column) - 1 + 2;
    }
    else{
        cows = abs(barn.row - lake.row) + abs(barn.column - lake.column) - 1;
    }
    out_stream << cows << endl;

}