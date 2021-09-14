#include <iostream>
#include <algorithm>
#include <string.h>
#define endl '\n'
using namespace std;

int N, X, tmp;
string ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> X;

    if(X < N || 26 * N < X) {
        cout << "!";
        return 0;
    }

    for(int i = 0; i < N; i++)
        ans += 'A';
    
    X = X - N;

    for(int i = N - 1; i >= 0; i--) {
        if(X <= 0)
            break;
        
        tmp = min(25, X);
        ans[i] += tmp;
        X = X - tmp;
    }

    cout << ans;
    return 0;
}