#include <iostream>
#include <queue>
#include <vector>
#define INF 1000000
using namespace std;

int dist[20001], V, E, K, u, v, w, curr, d, nx, nx_d;
vector<pair<int, int>> arr[20001];

void func(int start) {
    dist[start] = 0;
    priority_queue<pair<int, int>> Q;
    Q.push(make_pair(0, start));
    
    while(!Q.empty()) {
        curr = Q.top().second;
        d = -Q.top().first;
        Q.pop();
        
        if(dist[curr] < d)
            continue;
        for(int i = 0; i < arr[curr].size(); i++) {
            nx = arr[curr][i].first;
            nx_d = d + arr[curr][i].second;
            
            if(nx_d < dist[nx]) {
                dist[nx] = nx_d;
                Q.push(make_pair(-nx_d, nx));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> V >> E >> K;
    for(int i = 1; i <= V; i++)
        dist[i] = INF;
    
    for(int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        arr[u].push_back(make_pair(v, w));
    }
    
    func(K);
    
    for(int i = 1; i <= V; i++) {
        if(dist[i] == INF)
            cout << "INF" << endl;
        else
            cout << dist[i] << endl;
    }
    return 0;
}

