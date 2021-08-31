#include <iostream>
using namespace std;

int A_str, A_hp, B_str, B_hp, A, B;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> A_str >> A_hp >> B_str >> B_hp;

    while(true) {
        A_hp -= B_str;
        B_hp -= A_str;

        if(B_hp <= 0 && A_hp >= 1) {
            cout << "PLAYER A";
            return 0;
        }
        else if(A_hp <= 0 && B_hp >= 1) {
            cout << "PLAYER B";
            return 0;
        }
        else if(A_hp >= 1 && B_hp >= 1)
            continue;
        else {
            cout << "DRAW";
            return 0;
        }
    }
}