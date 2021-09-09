#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string.h>
#define ll long long
using namespace std;

ll N, ans;
bool flag;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ans = 1;
    string arr[1001];

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        reverse(arr[i].begin(), arr[i].end());
    }

    while(true) {
        map<string, ll> M;
        flag = true;
        ll chk = 1;
        for(int i = 0; i < N; i++) {
            if(M.find(arr[i].substr(0, ans)) != M.end()) {
                flag = false;
                break;
            }
            M[arr[i].substr(0, ans)]= 1 ;
        }
        if(flag == true)
            break;
        ans++;
    }
    cout << ans;
    return 0;
}