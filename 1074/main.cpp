#include <iostream>
using namespace std;

int N;
long long r, c;
long long num_low, num_high;
long long x_low, x_high;
long long y_low, y_high;
int main(){
    cin >> N;
    long long nSquare = 1;
    long long nNumbering = 1;
    for(int i = 0; i < N; i++) {
        nSquare =  2 * nSquare;
        nNumbering = 4 * nNumbering;
    }
    num_low = 0; num_high = nNumbering - 1;
    x_low = 0; x_high = nSquare - 1;
    y_low = 0; y_high = nSquare - 1;
    cin >> r >> c;
    while(nNumbering != 1) {
        if(r >= (y_low + y_high + 1) / 2) {
            num_low = (num_low + num_high + 1) / 2;
            y_low = (y_low + y_high + 1) / 2;
        }
        else {
            num_high = ((num_low + num_high + 1) / 2) - 1;
            y_high = ((y_low + y_high + 1) / 2) - 1;
        }
        if(c >= (x_low + x_high + 1) / 2) {
            num_low = (num_low + num_high + 1) / 2;
            x_low = (x_low + x_high + 1) / 2;
        }
        else {
            num_high = ((num_low + num_high + 1) / 2) - 1;
            x_high = ((x_low + x_high + 1) / 2) - 1;
        }
        nNumbering = nNumbering / 4;
    }
    cout << num_low;
    return 0;
}
