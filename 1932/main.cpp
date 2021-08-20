#include <iostream>
#include <algorithm>
using namespace std;
int arr[502][502], temp[502][502], n, ans = 0;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            cin >> temp[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            arr[i][j] = temp[i][j] +  max(arr[i - 1][j], arr[i - 1][j - 1]);
    for (int i = 1; i <= n; i++)
        ans = max(ans, arr[n][i]);
    cout << ans;
    return 0;
}