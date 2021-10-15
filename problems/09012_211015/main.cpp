#include <iostream>
#define endl '\n'
using namespace std;

int T, l, r;
bool flag;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    while(T--) {
        string input;
        cin >> input;

        l = r = 0;
        flag = false;
        for(int i = 0; i < input.length(); i++) {
            if(input[i] == '(') {
                l++;
            }
            else if(input[i] == ')') {
                r++;
            }
            if(r > l) {
                flag = true;
                break;
            }
        }
        if(input[0] == '(' && input[input.length() - 1] == ')' && l == r && flag == false) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}