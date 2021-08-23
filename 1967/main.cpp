#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

struct Node {
    int index;
    int dist;
};
int N, maxDist, maxNode, start, finish, dist;
bool visit[10001];
vector<Node> arr[10001];

void dfs(int node, int dist) {
    if (visit[node])
        return;
    if (maxDist < dist) {
        maxDist = dist;
        maxNode = node;
    }
    visit[node] = true;
    for(int i = 0; i < arr[node].size(); i++) {
        int nextIndex = arr[node][i].index;
        int nextDist = arr[node][i].dist;
        dfs(nextIndex, nextDist + dist);
    }
}

int main(void) {
    memset(visit, false, sizeof(visit));
    cin >> N;
    for (int i = 1; i < N; i++) {
        int node1, node2, cost;
        cin >> node1 >> node2 >> cost;
        arr[node1].push_back({node2, cost});
        arr[node2].push_back({node1, cost});
    }
    dfs(1, 0);
    memset(visit, false, sizeof(visit));
    maxDist = 0;
    dfs(maxNode, 0);
    cout << maxDist;
    return 0;
}