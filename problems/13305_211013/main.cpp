#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
#define lld long long
using namespace std;

int N;
lld ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ans = 0;
    cin >> N;
    vector<lld> dist(N);
    priority_queue<lld, vector<lld>, greater<lld>> q;

    for(int i = 0; i < N - 1; i++)
        cin>> dist[i];
    
    for(int i = 0; i < N; i++) {
        lld tmp;
        cin >> tmp;
        q.push(tmp);
        ans += q.top() * dist[i];
    }

    cout << ans;
    return 0;
}
