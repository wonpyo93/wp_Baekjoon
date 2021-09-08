#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 8
using namespace std;

int N, M, map[MAX];
vector<int> v;
bool visited[MAX];

void dfs(int index) {
    if (index == M) {
        for (int i = 0; i < M; i++)
            cout << map[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = 0; i < v.size(); i++) {
        if (visited[i])
            continue;
        visited[i] = true;
        map[index] = v[i];
        dfs(index + 1);
        visited[i] = false;
    }
}

int main() {
    cin >> N >> M;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    dfs(0);
}
