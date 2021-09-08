#include <iostream>
using namespace std;

int A, B, C, D, E, F, G, H, T;

int main() {
    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> A >> B >> C >> D >> E >> F >> G >> H;
        A += E;
        B += F;
        C += G;
        D += H;
        if(A < 1)
            A = 1;
        if(B < 1)
            B = 1;
        if(C < 0)
            C = 0;
        cout << A + (B * 5) + (C * 2) + (D * 2) << endl;
    }
    
    return 0;
}