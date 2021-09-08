#include <iostream>
#include <string.h>
#include <algorithm>
#define INF 987654321
using namespace std;
int N, M, a, b, c, arr[101][101];

void theAlgo() {
    for (int i = 1; i <= N; i++) { //거쳐가는 노드
        for (int j = 1; j <= N; j++) { //출발 노드
            for (int k = 1; k <= N; k++) { //도착 노드
                arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
            }
        }
    }
}

int main() {
    //initialize array with INF and 0
    fill(&arr[0][0], &arr[100][101], INF);
    for(int i = 0; i < 101; i++)
        arr[i][i] = 0;

    //receive input
    cin >> N >> M; //N = 도시의 개수, M = 버스의 개수
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        arr[a][b] = min(arr[a][b], c);
    }

    // //print initial arr
    // for(int i = 1; i <= N; i++) {
    //     for(int j = 1; j <= N; j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    //run algorithm
    theAlgo();

    //print final arr
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if(arr[i][j] == INF)
                cout << 0 << " ";
            else
                cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}