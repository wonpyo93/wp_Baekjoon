#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#define endl '\n'
using namespace std;

int N, idx, ans;
int T[1500001], P[1500001];
int arr[1500001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(arr, 0, sizeof(arr));

    cin >> N;

    idx = 0;
    ans = 0;

    for(int i = 0; i < N; i++)
        cin >> T[i] >> P[i];
    
    for(int i = N; i > 0; i--) {
        if(i + T[i - 1] - 1 > N) {
            arr[i - 1] = arr[i]; 
        }
        else {
            arr[i - 1] = max(arr[i], arr[i - 1 + T[i - 1]] + P[i - 1]);
        }
    }

    cout << arr[0];
    return 0;
}