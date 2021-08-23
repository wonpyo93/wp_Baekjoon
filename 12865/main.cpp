#include <iostream>
#include <algorithm>
using namespace std;

int N, K;

int main() {
    cin >> N >> K;
    int arr[N + 1][2], cnt[N + 1][K + 1];
    for(int i = 1; i < N + 1; i++)
        cin >> arr[i][0] >> arr[i][1];

    for(int i = 0; i < K + 1; i++)
        cnt[0][i] = 0;

    for(int i = 0; i < N + 1; i++)
        cnt[i][0] = 0;

    for(int i = 1; i < N + 1; i++) {
        for(int j = 0; j <= K; j++) {
            if(j < arr[i][0])
                cnt[i][j] = cnt[i - 1][j];
            else
                cnt[i][j] = max(cnt[i - 1][j], cnt[i - 1][j - arr[i][0]] + arr[i][1]);
        }
    }
    
    cout << cnt[N][K];
}