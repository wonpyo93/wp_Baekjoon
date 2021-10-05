#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int N, T, tmp, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    
    while(T--) {
        cin >> N;
        vector<pair<int,int>> arr;
        
        for(int i = 0; i < N; i++) {
            int x, y;
            cin >> x >> y;
            arr.push_back({x,y});
        }
        
        sort(arr.begin(), arr.end());
        
        tmp = 0;
        ans = 1;
        
        for(int i = 1; i < N; i++) {
            if(arr[tmp].second > arr[i].second) {
                ans++;
                tmp = i;
            }
        }
        cout << ans << endl;
    }
}