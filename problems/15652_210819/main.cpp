#include <iostream>
#include <string.h>
#define MAX 10
using namespace std;

int map[MAX], N, M;;
bool visited[MAX];

void dfs(int a, int count) {
    if(count == M) {
        for(int i = 0; i < M; i++)
            cout << map[i] << " ";
        cout << "\n";
        return;
    }
    for(int i = a; i <= N; i++) {
            visited[i] = true;
            map[count] = i;
            dfs(i, count+1);
            visited[i] = false;
    }
}

int main() {
    cin >> N >> M;
    memset(map, 0, sizeof(map));
    memset(visited, 0, sizeof(visited));
    dfs(1, 0);
}