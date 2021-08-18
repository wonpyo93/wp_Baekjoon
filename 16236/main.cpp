#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>
#define MAX 1000
using namespace std;

int map[MAX][MAX], visited[MAX][MAX], dist[MAX][MAX];
int n, ans, dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};

struct playerInfo { int x, y, size, count;};
using enemyInfo = tuple<int, int, int>;
using location = pair<int, int>;

playerInfo player;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
            if(map[i][j] == 9)
                player = {i,j,2,0};
        }
    }
    int check = 1;
    while(check == 1) {
        memset(dist,0,sizeof(dist));
        memset(visited,0,sizeof(visited));
        queue <location> q;
        vector <enemyInfo> enemy;
        q.push({player.x, player.y});
        visited[player.x][player.y] = 1;

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0 ; i < 4; i++) {
                int x_temp = x + dx[i];
                int y_temp = y + dy[i];
                if(0 > x_temp || x_temp >= n || 0 > y_temp || y_temp >= n)
                    continue;
                if(visited[x_temp][y_temp] || map[x_temp][y_temp] > player.size)
                    continue;
                visited[x_temp][y_temp] = 1;
                q.push({x_temp, y_temp});
                dist[x_temp][y_temp] = dist[x][y] + 1;
                if(map[x_temp][y_temp] && map[x_temp][y_temp] < player.size)
                    enemy.push_back({dist[x_temp][y_temp], x_temp, y_temp});
            }
        }
        
        if(!enemy.size())
            check = 0;
        else {
            sort(enemy.begin(),enemy.end());
            int d = get<0>(enemy[0]);
            int x = get<1>(enemy[0]);
            int y = get<2>(enemy[0]);
            ans += d;
            map[player.x][player.y] = 0;
            player.x = x;
            player.y = y;
            player.count++;
            map[x][y] = 0;

            if(player.count == player.size) {
                player.size++;
                player.count = 0;
            }
            check = 1;
        }
    }
    cout << ans;
}