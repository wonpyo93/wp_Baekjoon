#include <iostream>
#include <string.h>
using namespace std;

long long N;
long long arr[101010];
long long cnt[101010];
long long tmp, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ans = 0;
    cin >> N;

    for(long long n = 1; n < N + 1; n++) {
        cin >> tmp;
        arr[n] = tmp;
        cnt[tmp]++;
    }

    cnt[arr[1]]--;
    for(long long j = 2; j < N; j++) {
        cnt[arr[j]]--;
        for(long long i = 1; i < j; i++) {
            tmp = arr[j] * 2 - arr[i];
            ans += cnt[tmp];
        }
    }

    cout << ans;
    return 0;
}