#include <iostream>
using namespace std;

int main() {
    long x1, y1, r1, x2, y2, r2, d, z;
    cin >> z;
    for(int i = 0; i < z; i++) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        d = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
        //exactly same
        if(d == 0){
            if(r1 == r2)
                cout << -1;
            else
                cout << 0;
        }
        //one point
        else if(d == (r1 + r2)*(r1 + r2) || d == (r1 - r2)*(r1 - r2))
            cout << 1;
        //two points
        else if(d < (r1 + r2)*(r1 + r2) && d > (r1 - r2)*(r1 - r2))
            cout << 2;
        //else--> no point
        else if(d > (r1 + r2)*(r1 + r2) || d < (r1 - r2)*(r1 - r2))
            cout << 0;
        cout << "\n";
    }
    return 0;
}