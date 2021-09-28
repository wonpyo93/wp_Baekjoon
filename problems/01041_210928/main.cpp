#include <iostream>
#include <vector>
#include <functional>
#include <numeric>
#include <cmath>
#include <algorithm>

#define ll long long
#define endl '\n'
#define MAX 987654321

using namespace std;

ll N, ans;
int V, S, tmp;
vector<int> d1(6), d2(6);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    ans = 0;
    V = MAX;
    S = MAX;

    for (auto& c : d1)
        cin >> c;
    
    d2[0] = d1[4];
    d2[1] = d1[0];
    d2[2] = d1[1];
    d2[3] = d1[5];
    d2[4] = d1[3];
    d2[5] = d1[2];


    if (N == 1) {
        cout << accumulate(d1.begin(), d1.end(), 0) - *max_element(d1.begin(), d1.end()) << endl;
        return 0;
    }

    for (int i = 0; i < 4; i++) {
        tmp = d2[i] + d2[(i + 1) % 4];

        V = min(V, tmp + d2[4]);
        V = min(V, tmp + d2[5]);
    }

    for (int i = 0; i < 4; i++) {
        S = min(S, d2[i] + d2[(i + 1) % 4]);

        S = min(S, d2[i] + d2[4]);
        S = min(S, d2[i] + d2[5]);
    }

    ans += V * 4;
    ans += S * (8 * N - 12);
    ans += *min_element(d1.begin(), d1.end()) * (5 * N * N - (16 * N) + 12);

    cout << ans << endl;
    return 0;
}