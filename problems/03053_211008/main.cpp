#include <iostream>
#include <math.h>
#define endl '\n'
using namespace std;

int N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    
    cout << fixed;
    cout << atan(1) * 4 * N * N << endl;
    cout << (double)N * N * 2;
    return 0;
}