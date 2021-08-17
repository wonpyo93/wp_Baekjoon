#include<iostream>
#include<queue>
using namespace std;
 
#define MAX 2222
int N, M, V;
int map[MAX][MAX];
int visit[MAX];

void bfs(int v) {
    queue<int> q;
    q.push(v);
    visit[v] = 0;
    while(!q.empty()) {
        v = q.front();
        cout << q.front() << " ";
        q.pop();
        for(int i = 1; i <= N; i++) {
            if(visit[i] == 0 || map[v][i] == 0)
                continue;
            q.push(i);
            visit[i] = 0;
        }
    }
}

void dfs(int v) {
    cout << v << " ";
    visit[v] = 1;
    for(int i=1; i<=N; i++) {
        if(visit[i] == 1 || map[v][i] == 0)     
            continue;
        dfs(i);
    }
}
 
int main() {
    int x, y;
    cin >> N >> M >> V;
    for(int i = 0; i < M; i++) {
        cin >> x >> y;            
        map[x][y] = map[y][x] = 1;
    }
    dfs(V);            
    cout << "\n";
    bfs(V);
    return 0;
}
