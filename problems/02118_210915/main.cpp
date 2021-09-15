#include <iostream>
#include <algorithm>
#include <string.h>
#define lld long long
using namespace std;

int ans, N, arr[50001], sum[50001], rev[50001];

int search(int arr[], int N, const int& v){
    int l=0, r=N-1;
    while(l <= r){
        int m = (l+r)/2;
        if(arr[m] == v) return arr[m];
        else if(arr[m] < v) l = m+1;
        else r = m-1;
    }
    return arr[r];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    
    memset(arr, 0, sizeof(arr));
    memset(sum, 0, sizeof(sum));
    memset(rev, 0, sizeof(rev));
    
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        sum[i + 1] = sum[i];
        sum[i + 1] += arr[i];
    }
    
    int totalSum = sum[N];
    int midSum = totalSum / 2;
    
    for(int i = 0; i < N; i++)
        rev[N - i] = totalSum - sum[i];
    
    ans = 0;

    for(int i = 0; i < N; i++) {
        int tmp = search(sum + i + 1, N - i, midSum + sum[i]) - sum[i];
        ans = max(ans, min(tmp, totalSum - tmp));
    }
    
    for(int i = 0; i < N; i++) {
        int tmp = search(rev, N - i, midSum - sum[i]) + sum[i];
        ans = max(ans, min(tmp, totalSum - tmp));
    }
    
    cout << ans;
    return 0;
}