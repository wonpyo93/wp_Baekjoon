#include <iostream>
#include <algorithm>
using namespace std; 

const int INF = 978645312;
const int MAX = 101;
int N, M, x, y, counter = INF, ans, map[MAX][MAX];

void theAlgo() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                if (j == k)
                    continue;
                else if (map[j][i] && map[i][k]) {
                    if (map[j][k] == 0)
                        map[j][k] = map[j][i] + map[i][k];
                    else
                        map[j][k] = min(map[j][k], map[j][i] + map[i][k]);
                }
            }
        }
    }
}
int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        map[x][y] = 1;
        map[y][x] = 1;
    }
    theAlgo();
    for (int i = 1; i <= N; i++) {
        int sum = 0;
        for (int j = 1; j <= N; j++)
            sum += map[i][j];
        if (counter > sum) {
            counter = sum;
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}