#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#define endl '\n'
using namespace std;

int N, S, M;
int arr[101], choice[101][1001];

int func(int a, int n) {
    if(a == N)
        return n;

    int& ans = choice[a][n];
    
    if(ans != -1)
        return ans;
    
    if(n - arr[a + 1] >= 0)
        ans = max(ans, func(a + 1,n - arr[a + 1]));
    
    if(n + arr[a + 1] <= M)
        ans = max(ans, func(a + 1,n + arr[a + 1]));
    
    if(ans == -1)
        ans = -2;
    
    return ans;
}

int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> S >> M;
    
    for(int i = 1; i <= N ; i++)
    cin >> arr[i];

    memset(choice , -1, sizeof(choice));
    int ans = func(0, S);

    if(ans == -2)
        cout << "-1";
    else
        cout << ans;
    return 0;
}