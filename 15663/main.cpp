#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define MAX 8
using namespace std;

vector<int> V;
map<int, int> visitCount;
int N, M, visited[MAX], input;

void dfs(int index, int count) {
	if (count == M) {
		for (int i = 0; i < M; i++)
			cout << V[visited[i]] << " ";
		cout << "\n";
		return;
	}

	if (index == N)
		return;

	for (int i = 0; i < V.size(); i++) {
		if (visitCount[V[i]]) {
			visitCount[V[i]]--;
			visited[index] = i;
			dfs(index + 1, count + 1);
			visitCount[V[i]]++;
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> input;
		if (!visitCount.count(input)) {
			visitCount[input] = 1;
			V.push_back(input);
		}
		else
			visitCount[input]++;
	}
	sort(V.begin(), V.end());
	dfs(0, 0);

	return 0;
}