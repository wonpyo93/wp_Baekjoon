#include <iostream>
#include <queue>
#include <string.h>
#define MAX 51
using namespace std;

int N, M, t_num, temp;
int T[MAX], P[MAX][MAX], S[MAX], P_NUM[MAX][MAX], checked[MAX], ans[MAX];
queue<int> Q;

int main() {
    memset(T, 0, sizeof(T));
    memset(P, 0, sizeof(P));
    memset(S, 0, sizeof(S));
    memset(P_NUM, 0, sizeof(P_NUM));
    memset(checked, 0, sizeof(checked));
    memset(ans, 0, sizeof(ans));
    cin >> N >> M;
    cin >> t_num;
    for(int i = 1; i < t_num + 1; i++) {
        cin >> temp;
        T[temp] = 1;
        Q.push(temp);
    }
    for(int i = 1; i < M + 1; i++) {
        cin >> S[i];
        for(int j = 1; j < S[i] + 1; j++) {
            cin >> temp;
            P_NUM[i][j] = temp;
            P[i][temp] = 1;
        }
    }
    while(Q.size() != 0) {
        int temp = Q.front();
        Q.pop();
        if(checked[temp] == 0) {
            checked[temp] = 1;
            for(int i = 1; i < M + 1; i++) {
                if(P[i][temp] == 1 && ans[i] == 0) {
                    ans[i] = 1;
                    for(int j = 1; j < S[i] + 1; j++) {
                        Q.push(P_NUM[i][j]); 
                    }
                }
            }
        }
    }
    for(int i = 0; i < MAX; i++)
        M = M - ans[i];
    cout << M;
}