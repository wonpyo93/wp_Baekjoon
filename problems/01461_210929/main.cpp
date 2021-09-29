#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

int N, M, cnt, ans;
int arr[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cnt = 0;
    ans = 0;
    
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        if(arr[i] < 0)
            cnt++;
    }

    sort(arr, arr + N);

    for(int i = N - 1; i >= cnt; i -= M)
        ans += arr[i] * 2;

    for(int i = 0; i < cnt; i += M)
        ans += abs(arr[i] * 2);

    ans -= max(abs(arr[0]), abs(arr[N - 1]));

    cout << ans;
}