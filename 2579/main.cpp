#include <iostream>
#include <algorithm>
using namespace std;

int N, arr[301], dp[301][2];

int main() {
    cin >> N;
    for(int i = 1; i < N + 1; i++)
        cin >> arr[i];
    
    dp[1][0] = arr[1];

    for(int i = 2; i < N + 1; i++) {
        dp[i][1] = dp[i - 1][0] + arr[i];
        dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + arr[i];
    }

    cout << max(dp[N][0], dp[N][1]);

    return 0;
}