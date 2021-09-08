#include <iostream>
#include <string.h>
#define endl '\n'
using namespace std;

char ans[50], dna[1000][50];
int cnt, N, M;

enum INFO {A, C, G, T, INFO_END};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int info[50][INFO_END];
    cnt = 0;
    memset(dna, 0, sizeof(dna));
    memset(info, 0, sizeof(info));
    memset(ans, 0, sizeof(ans));

    cin >> N >> M;

    for(int i = 0; i < N; i++)
        cin >> dna[i];
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            switch(dna[i][j]) {
                case 'A':
                    info[j][A]++;
                    break;
                case 'C':
                    info[j][C]++;
                    break;
                case 'G':
                    info[j][G]++;
                    break;
                case 'T':
                    info[j][T]++;
                    break;
            }
        }
    }

    for(int i = 0; i < M; i++) {
        char tmp = 0;
        int max = 0;
        for(int j = 0; j < INFO_END; j++) {
            if(max < info[i][j]) {
                switch (j) {
                    case A: 
                        tmp = 'A';
                        break;
                    case C:
                        tmp = 'C';
                        break;
                    case G:
                        tmp = 'G';
                        break;
                    case T:
                        tmp = 'T';
                        break;
                }
                max = info[i][j];
            }
        }
        ans[i] = tmp;
    }

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(ans[j] != dna[i][j]) 
                cnt++;

    cout << ans << endl;
    cout << cnt;
    return 0;
}
