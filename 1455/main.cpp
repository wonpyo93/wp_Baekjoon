#include <iostream>
#define endl '\n'
using namespace std;

char arr[100][100];
int N, M, ans, maxN, maxM;

// void printArr() {
//     for(int i = 0; i < maxN; i++) {
//         for(int j = 0; j < maxM; j++) {
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << endl;
// }

void flip(int a, int b) {
    for(int i = 0; i <= a; i++) {
        for(int j = 0; j <= b; j++) {
            if(arr[i][j] == '0') arr[i][j] = '1';
            else arr[i][j] = '0';
        }
    }
    // printArr();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    maxN = N; maxM = M;
    ans = 0;

    //initialize arr
    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < str.size(); j++) {
            arr[i][j] = str[j];
        }
    }

    // printArr();

    while(N > 0 && M > 0) {
        //check 가로 끝
        for(int i = M - 1; i >= 0; i--) {
            // cout << "checking " << N - 1 << " " << i << endl;
            if(arr[N - 1][i] == '1') {
                flip(N - 1, i);
                ans++;
            }
        }
        N--;
        //check 세로 끝
        for(int i = N - 1; i >= 0; i--) {
            // cout << "checking " << i << " " << M - 1 << endl;
            if(arr[i][M - 1] == '1') {
                flip(i, M - 1);
                ans++;
            }
        }
        M--;
    }
    cout << ans;
    return 0;
}