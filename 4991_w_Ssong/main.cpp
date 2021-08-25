#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

struct NODE {
	int x, y;
};
NODE node[11];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char arr[21][21];
int path[21][21];
bool visited[11];
int W, H, idx, ans;

void BFS(int start_x, int start_y, int num_d, int self) {
	queue<NODE> Q;
	bool visit[21][21];
    memset(visit, 0, sizeof(visit));
	Q.push({start_x, start_y});
	visit[start_x][start_y] = true;
	int nPath = 0;
	int cnt = num_d;
	bool flag;

	while(!Q.empty()) {
		flag = false;
		int qSize = Q.size();

		for(int i = 0; i < qSize; i++) {
			int cur_x = Q.front().x;
			int cur_y = Q.front().y;
			Q.pop();
			
			if(arr[cur_x][cur_y] == '*' 
                    && (cur_x != node[self].x || cur_y != node[self].y)) {
				cnt--;
				for(int i = 1; i <= num_d + 1; i++) {
					if(cur_x == node[i].x && cur_y == node[i].y) {
						path[self][i] = nPath;
						break;
					}
				}
				if (!cnt) return;
			}

			for(int j = 0; j < 4; ++j) {
				int next_x = cur_x + dx[j];
				int next_y = cur_y + dy[j];

				if (next_x < 0 || next_y < 0 || next_x >= H || next_y >= W 
                        || visit[next_x][next_y] || arr[next_x][next_y] == 'x')
                    continue;
				
				visit[next_x][next_y] = true;
				Q.push({ next_x, next_y });
				flag = true;
			}
		}
		if(flag)
            nPath++;
	}
}

void DFS(int curr, int total, int cnt, bool visited[]) {
	if(ans <= total) return;

	if(cnt == 0) {
		ans = total;
		return;
	}

	for(int i = 1; i < idx; i++) {
		int cur_x = node[curr].x;
		int cur_y = node[curr].y;

		if (i == curr || visited[i] || (ans <= total + path[curr][i]))
            continue;

		visited[i] = true;
		DFS(i, total + path[curr][i], cnt - 1, visited);
		visited[i] = false;
	}
}

int main() {
	while(1) {
		ans = 87654321;
		idx = 1;
        
        cin >> W >> H;
		if(W == 0 && H == 0)
            break;

        for(int i = 0; i < H; i++) {
            scanf(" %s", arr[i]);
            for(int j = 0; j < W; j++) {
                if(arr[i][j] == '*') {
                    node[idx].x = i;
                    node[idx].y = j;
                    idx++;
                }
                else if(arr[i][j] == 'o') {
                    node[0].x = i;
                    node[0].y = j;
                }
            }
        }
        memset(path, -1, sizeof(path));

		bool check = false;
		BFS(node[0].x, node[0].y, idx - 1, 0);

		for(int i = 1; i < idx; i++) {
			if(path[0][i] == -1) {
				check = true;
				break;
			}
		}

		if(check) {
            cout << -1 << endl;
			continue;
		}
		
		for(int i = 1; i <= idx; i++)
			BFS(node[i].x, node[i].y, idx - 2, i);

        memset(visited, 0, sizeof(visited));

		visited[0] = true;
		DFS(0, 0, idx - 1, visited);

        cout << ans << endl;
	}
	return 0;
}