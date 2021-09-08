#include <iostream>
#include <algorithm>
#include <string.h>
#define MAX 1001
using namespace std;

int N, ans = 978645312, arr_a[MAX][3], arr_b[MAX][3];

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    memset(arr_a, 0, sizeof(arr_a));
    memset(arr_b, 0, sizeof(arr_b));
    cin >> N;
    for(int i = 0; i < N; i++)
        for (int j = 0; j < 3; j++)
            cin >> arr_a[i][j];

    for(int i = 0; i < 3; i++)
        arr_b[0][i] = arr_a[0][i];

    //start with r
    arr_b[0][0] = arr_a[0][0];
    arr_b[0][1] = 999999;
    arr_b[0][2] = 999999;
    for(int i = 1; i < N; i++) {
        arr_b[i][0] = min(arr_b[i - 1][1], arr_b[i - 1][2]) + arr_a[i][0];
        arr_b[i][1] = min(arr_b[i - 1][0], arr_b[i - 1][2]) + arr_a[i][1];
        arr_b[i][2] = min(arr_b[i - 1][0], arr_b[i - 1][1]) + arr_a[i][2];
    }
    if(arr_b[N - 1][1] < ans) ans = arr_b[N - 1][1];
    if(arr_b[N - 1][2] < ans) ans = arr_b[N - 1][2];

    
    //start with g
    arr_b[0][0] = 999999;
    arr_b[0][1] = arr_a[0][1];
    arr_b[0][2] = 999999;
    for(int i = 1; i < N; i++) {
        arr_b[i][0] = min(arr_b[i - 1][1], arr_b[i - 1][2]) + arr_a[i][0];
        arr_b[i][1] = min(arr_b[i - 1][0], arr_b[i - 1][2]) + arr_a[i][1];
        arr_b[i][2] = min(arr_b[i - 1][0], arr_b[i - 1][1]) + arr_a[i][2];
    }
    if(arr_b[N - 1][0] < ans) ans = arr_b[N - 1][0];
    if(arr_b[N - 1][2] < ans) ans = arr_b[N - 1][2];

    //start with b
    arr_b[0][0] = 999999;
    arr_b[0][1] = 999999;
    arr_b[0][2] = arr_a[0][2];
    for(int i = 1; i < N; i++) {
        arr_b[i][0] = min(arr_b[i - 1][1], arr_b[i - 1][2]) + arr_a[i][0];
        arr_b[i][1] = min(arr_b[i - 1][0], arr_b[i - 1][2]) + arr_a[i][1];
        arr_b[i][2] = min(arr_b[i - 1][0], arr_b[i - 1][1]) + arr_a[i][2];
    }
    if(arr_b[N - 1][0] < ans) ans = arr_b[N - 1][0];
    if(arr_b[N - 1][1] < ans) ans = arr_b[N - 1][1];

    cout << ans;
    return 0;
}