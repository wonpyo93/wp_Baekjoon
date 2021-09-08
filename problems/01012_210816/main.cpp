#include <iostream>
#include <string.h>
using namespace std;
 
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int T, M, N, K, X, Y, ans;
int map[51][51];
int visited[51][51];
 
void recursiveFunc(int y, int x) {
    for(int i = 0; i < 4; i++) {
        int t_x = x + dx[i];
        int t_y = y + dy[i];
        if(t_y < 0 || t_y >= N || t_x < 0 || t_x >= M)
            continue;
        if(map[t_y][t_x] && !visited[t_y][t_x]) {
            visited[t_y][t_x]++;
            recursiveFunc(t_y,t_x);
        }
    }
}

int main(){
    cin >> T;
    for(int t = 0; t < T; t++) {
        ans = 0;
        cin >> M >> N >> K;        
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));
        
        for(int i = 0; i < K; i++) {
            cin >> X >> Y;
            map[Y][X] = 1;
        }
        
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                if(map[i][j] && !visited[i][j]) {
                    ans++;
                    visited[i][j]++;
                    recursiveFunc(i, j);
                }
        cout << ans << endl;
    }
    return 0;
}
