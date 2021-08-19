#include <iostream>
#include <algorithm>
#define MAX 8
using namespace std;

int N, M, map[MAX], visited[MAX];

void dfs(int idx, int start, int count) {
	if (count == M) {
		for (int i = 0; i < M; i++)
			cout << map[visited[i]] << " ";
		cout << "\n";
		return;
	}

	if(idx == N)
		return;

	for (int i = start; i < N; i++) {
		visited[idx] = i;
		dfs(idx + 1, i, count + 1);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> map[i];
	sort(map, map + N);
	dfs(0, 0, 0);
	return 0;
}