#include <iostream>
#include <math.h>
#include <algorithm>
#define endl '\n'
using namespace std;

int N, ans, maxdiff, maxidx, tmp;
int chkpt[100001][2];
int dist1[100001];
int dist2[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> chkpt[0][0] >> chkpt[0][1];
    for(int i = 1; i < N; i++) {
        cin >> chkpt[i][0] >> chkpt[i][1];
        dist1[i - 1] = abs(chkpt[i][0] - chkpt[i - 1][0]) + abs(chkpt[i][1] - chkpt[i - 1][1]);
    }

    for(int i = 2; i < N; i++)
        dist2[i - 2] = abs(chkpt[i][0] - chkpt[i - 2][0]) + abs(chkpt[i][1] - chkpt[i - 2][1]);

    maxdiff = 0;
    ans = 0;

    for(int i = 0; i < N - 2; i++) {
        tmp = maxdiff;
        maxdiff = max(maxdiff, dist1[i] + dist1[i + 1] - dist2[i]);
        if(tmp != maxdiff)
            maxidx = i+1;
    }
    
    //verification start
    // cout << maxidx << endl;

    // for(int i = 0; i < N - 1; i++)
    //     cout << dist1[i] << " ";
    // cout << endl;

    // for(int i = 0; i < N - 2; i++)
    //     cout << dist2[i] << " ";
    // cout << endl;
    //verification finish

    for(int i = 0; i < N - 1; i++) {
        if(i != maxidx)
            ans += dist1[i];
        else {
            ans += dist2[i - 1];
            ans -= dist1[i - 1];
        }
    }

    cout << ans;
    return 0;
}