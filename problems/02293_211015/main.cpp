#include <iostream>
#include <string.h>
#define endl '\n'
using namespace std;

int N, K, coin[101], cache[10001];

//전형적인 coin DP 문제.
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    for(int i = 0; i < N; i++)
        cin >> coin[i];

    memset(cache, 0, sizeof(cache));
    cache[0] = 1;

    for(int i = 0; i < N; i++)
        for(int j = coin[i]; j <= K; j++) {
            cache[j] = (cache[j] + cache[j - coin[i]]);
        }
    
    // for(int i = 0; i <= K; i++)
    //     cout << cache[i] << "\t";
    // cout << endl;

    cout << cache[K];
    return 0;
}