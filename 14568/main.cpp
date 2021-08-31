#include <iostream>
using namespace std;

int N, ans;

int main() {
    ans = 0;
    cin >> N;
    for(int i = 2; i < N - 1; i+=2)
        ans += (N - i - 2) / 2;
    cout << ans;
    return 0;
}