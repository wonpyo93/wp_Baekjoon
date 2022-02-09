#include <iostream>
#include <string.h>
#include <regex>
using namespace std;

void solve() {
    string S;
    cin >> S;
    regex reg("(100+1+|01)+");
    cout << (regex_match(S, reg) ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    for(int t = 0; t < T; t++)
        solve();
}
