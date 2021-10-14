#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;
 
int N, M, x, y, cnt;
int visited[20001];
vector<vector<int> > adj(20001);
vector<int> ans;
 
void bfs() {
    queue<int> q;

    q.push(1);
    visited[1] = 1;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(auto& nx : adj[cur]) {
            if(visited[nx])
                continue;
            if(visited[cur] + 1 == cnt) {
                visited[nx] = visited[cur] + 1;

                q.push(nx);
                ans.push_back(nx);
            }
            else if(visited[cur] + 1 > cnt) {
                ans.clear();
                visited[nx] = visited[cur] + 1;
                q.push(nx);

                cnt = visited[nx];
                ans.push_back(nx);
                
            }
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cnt = 1;
    
    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    bfs();

    sort(ans.begin(), ans.end());

    cout << ans[0] << " " << visited[ans[0]] - 1 << " " << ans.size();
    return 0;
}
