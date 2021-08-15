#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 847593748
using namespace std;

int minTroop[3][10001], N, W, numToFill[2][10001];

void solve(void) {
    for(int i = 2; i <= N; i++) {
        int outer = 2 - (numToFill[0][i] + numToFill[0][i - 1] <= W);
        int inner = 2 - (numToFill[1][i] + numToFill[1][i - 1] <= W);
        int horizon = 2 - (numToFill[0][i] + numToFill[1][i] <= W);

        minTroop[0][i] = min(minTroop[2][i - 1] + 1, minTroop[1][i - 1] + outer);
        minTroop[1][i] = min(minTroop[2][i - 1] + 1, minTroop[0][i - 1] + inner);
        minTroop[2][i] = min({ minTroop[2][i - 1] + horizon, minTroop[0][i] + 1, minTroop[1][i] + 1, minTroop[2][i-2] + outer + inner});
    }
    return;
}

int main() {
    ios:: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> N >> W;
        for(int i = 0; i < 2; i++) {
            for(int j = 1; j <= N; j++) {
                cin >> numToFill[i][j];
            }
        }

        if(N == 1) {
            cout << 2 - (numToFill[0][1] + numToFill[1][1] <= W) << '\n';
            continue;
        }

        int ans = INF;
        memset(minTroop, 0, sizeof(minTroop));

        minTroop[0][1] = minTroop[1][1] = 1;
        minTroop[2][1] = 2 - (numToFill[0][1] + numToFill[1][1] <= W);
        solve();

        ans = min(ans, minTroop[2][N]);
        if(numToFill[0][N] + numToFill[0][1] <= W) {
            minTroop[2][0] = INF;
            minTroop[0][1] = 1;
            minTroop[1][1] = INF;
            minTroop[2][1] = 2;
            solve();
            ans = min(ans, minTroop[1][N]);
        }
        
        if(numToFill[1][N] + numToFill[1][1] <= W) {
            minTroop[2][0] = INF;
            minTroop[0][1] = INF;
            minTroop[1][1] = 1;
            minTroop[2][1] = 2;
            solve();
            ans = min(ans, minTroop[0][N]);
        }
        
        if(numToFill[0][N] + numToFill[0][1] <= W && numToFill[1][N] + numToFill[1][1] <= W) {
            minTroop[2][0] = INF;
            minTroop[0][1] = INF;
            minTroop[1][1] = INF;
            minTroop[2][1] = 2;
            solve();
            ans = min(ans, minTroop[2][N - 1]);
        }

        cout << ans << '\n';
        
    }
}
