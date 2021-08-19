#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define MAX 8
using namespace std;

int N, M, arr[MAX], input;
map<int, bool> visited;
vector<int> v;

void dfs(int index, int start, int count) {
	if (count == M) {
		for (int i = 0; i < M; i++)
			cout << v[arr[i]] << " ";
		cout << "\n";
		return;
	}

	for (int i = start; i < v.size(); i++) {
		arr[index] = i;
		dfs(index + 1, i, count + 1);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> input;
		if (!visited.count(input)) {
			visited[input] = true;
			v.push_back(input);
		}
	sort(v.begin(), v.end());
	dfs(0, 0, 0);
	return 0;
}