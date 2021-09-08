#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

struct Node {
    int index;
    int dist;
};
int V, maxDist, maxNode, start, finish, dist;
bool visit[100001];
vector<Node> arr[100001];

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
int main() {
    cin >> V;
    for(int i = 1; i < V + 1; i++) {
        cin >> start;
        while(true) {
            cin >> finish;
            if (finish == -1)
                break;
            cin >> dist;
            arr[start].push_back({finish, dist});
            arr[finish].push_back({start, dist});
        }
    }
    dfs(1, 0);
    memset(visit, 0, sizeof(visit));
    maxDist = 0;
    dfs(maxNode, 0);

    cout << maxDist;
    return 0;
}