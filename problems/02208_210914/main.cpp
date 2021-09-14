#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

int N, M, ans, tmp;
int arr[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> tmp;
        arr[i + 1] = arr[i] + tmp;
    }

    tmp = 0;
    for(int i = M - 1; i < N; i++) {
        tmp = min(tmp, arr[i - M + 1]);
        ans = max(ans, arr[i + 1] - tmp);
    }

    cout << ans;
    return 0;
}