#include <iostream>
#include <string.h>
#include <algorithm>
#define endl '\n'
using namespace std;

int dy[4]={1, -1, 0, 0};
int dx[4]={0, 0,  1, -1};
int cnt, ans, N, arr[100][100], visited[100][100];

void dfs(int y, int x, int h) {
    
    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= N || nx < 0 || nx >= N)
            continue;
        
        if(arr[ny][nx] <= h || visited[ny][nx])
            continue;
        
        visited[ny][nx]++;
        dfs(ny, nx, h);
    }

}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(arr, 0, sizeof(arr));
    memset(visited, 0, sizeof(visited));

    ans = 1;
    cin >> N;
    
    int minH = 100;
    int maxH = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
            minH = min(minH, arr[i][j]);
            maxH = max(maxH, arr[i][j]);
        }
    }

    for(int h = minH; h < maxH; h++) {
        memset(visited,0,sizeof(visited));
        cnt = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(arr[i][j] > h && !visited[i][j]) {
                    visited[i][j]++;
                    cnt++;
                    dfs(i,j,h);
                }
            }
        }
        ans=max(ans,cnt);
    }
   
    cout << ans << endl;
    return 0;
}
