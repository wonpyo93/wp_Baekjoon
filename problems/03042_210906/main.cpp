#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
char arr[101][101];
vector<pair<int, int>> vec;
 
bool ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    int tmp = (x1 * y2) + (x2 * y3) + (x3 * y1);
    tmp -= ((y1 * x2) + (y2 * x3) + (y3 * x1));
    if(!tmp)
        return true;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if('A' <= arr[i][j] && arr[i][j] <= 'Z')
                vec.push_back({i, j});
        }
    }

    int m = vec.size();
    int ans = 0;
    for(int i = 0; i < m; i++) {
        for(int j = i + 1; j < m; j++) {
            for(int k = j + 1; k < m; k++) {
                if(ccw(vec[i].first, vec[i].second, vec[j].first, vec[j].second, vec[k].first, vec[k].second))
                    ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
