#include <iostream>
#include <algorithm>
using namespace std;

long long X, x, B;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> X >> B;
    x = X;

    //preprocessing
    if(B > 0) { //양수의 진수일 때
        if(X < 0) { //X가 음수일 때
            X = -X;
        }
    }
    else { //음수의 진수일 때
        
    }

    while(x != 0) {

    }

    return 0;
}