#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>
#include <set>
#define endl '\n'
using namespace std;

string N, ans;
int K, sz, l;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    queue<string> q;

    cin >> N >> K;
    l = N.size();
    q.push(N);

    for(int z = 0; z < K; z++) {
        sz = q.size();
        set<string> s;

        for(int i = 0; i < sz; i++) {
            string cur = q.front();
            q.pop();
            if(s.count(cur))
                continue;
            s.insert(cur);

            for(int j = 0; j < l - 1; j++) {
                for(int k = j + 1; k < l; k++) {
                    if(cur[k] != '0' || j > 0) {
                        swap(cur[j], cur[k]);
                        q.push(cur);
                        swap(cur[j], cur[k]);
                    }
                }
            }
        }
    }
    ans = "0";
    while(!q.empty()) {
        ans = max(ans, q.front());
        q.pop();
    }
    if(ans[0] == '0')
        cout << -1;
    else
        cout << ans;
    return 0;
}