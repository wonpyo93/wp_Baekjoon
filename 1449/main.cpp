#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int N, L, tmp, ans, start;
vector<int> vec;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> L;

    for(int i = 0; i < N; i++) {
        cin >> tmp;
        vec.push_back(tmp);
    }
    ans = 1;

    sort(vec.begin(), vec.end());
    start = vec[0];
    
    for(int i = 1; i < N; i++) {
        if(L - 1 < vec[i] - start) {
            ans++;
            start = vec[i];
        }
    }
    cout << ans;
}