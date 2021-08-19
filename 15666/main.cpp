#include <iostream>
#include <algorithm>
#define MAX 8
using namespace std;

int N, M, map[MAX], visited[MAX];

void dfs(int index) {
	if (index == M) {
		for (int i = 0; i < M; i++)
			cout << map[visited[i]] << " ";     
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; i++) {
		visited[index] = i;
		dfs(index + 1);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> map[i];
	sort(map, map + N);
	dfs(0);

	return 0;
}