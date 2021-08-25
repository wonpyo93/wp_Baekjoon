#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, ans, from, to, tmp;
int arr[101][101];
bool visited[101];
queue<int> q;

void bfs(int v) {
	q.push(v);
	visited[v] = true;

	while(!q.empty()) {
		tmp = q.front();
		q.pop();

		for(int i = 1; i < N + 1; i++) {
            if(visited[i] == true || arr[tmp][i] == 0)
                continue;
            visited[i] = true;
            q.push(i);
            ans++;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    ans = 0;

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> from >> to;
		arr[from][to] = 1;
		arr[to][from] = 1;
	}

	bfs(1);	

	cout << ans;

	return 0;
}

