#include <iostream>
#define endl '\n'

using namespace std;

int N, visited[31][31];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
double prob[4];

double dfs(int x, int y, int cnt) {
    double ans = 0.0;
    if(cnt == 0)
        return 1.0;
    else {
        visited[x][y] = true;
        for(int i = 0; i < 4; i++) {
            int t_x = x + dx[i];
            int t_y = y + dy[i];
            if(visited[t_x][t_y])
                continue;
            ans += dfs(t_x, t_y, cnt - 1) * prob[i];
        }
        visited[x][y] = false;
        return ans;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 0; i < 4; i++) {
        cin >> prob[i];
        prob[i] = prob[i] / 100.0;
    }
    printf("%.9lf", dfs(15, 15, N));
    return 0;
}