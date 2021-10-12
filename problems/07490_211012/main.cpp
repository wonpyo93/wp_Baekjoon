#include <iostream>
#include <string.h>
#define endl '\n'
using namespace std;

int T, N;

void solve(int sum, int sign, int num, int n, string str) {
    if (n == N) {
        sum += (num * sign);
        if (sum == 0)
            cout << str << endl;
    }
    else {
        solve(sum, sign, num * 10 + (n + 1), n + 1, str + ' ' + char(n + 1 + '0'));
        solve(sum + (sign*num), 1, n + 1, n + 1, str + '+' + char(n + 1 + '0'));
        solve(sum + (sign*num), -1, n + 1, n + 1, str + '-' + char(n + 1 + '0'));
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    char test;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        solve(0, 1, 1, 1, "1");
        cout << endl;
    }
    return 0;
}
