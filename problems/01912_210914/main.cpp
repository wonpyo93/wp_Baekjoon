#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

int N, ans;
int arr[100001], dp[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    dp[0] = arr[0];
    ans = arr[0];

    for(int i = 1; i < N; i++) {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        ans = max(ans, dp[i]);
    }

    cout << ans;
    return 0;
}