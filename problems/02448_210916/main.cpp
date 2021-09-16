#include <iostream>
#define endl '\n'
using namespace std;

int N;
char arr[4000][7000];

void solve(int x, int y , int n) { 
    if(n == 3) {
        arr[x][y] = '*';

        arr[x + 1][y - 1] = '*';
        arr[x + 1][y + 1] = '*';

        arr[x + 2][y - 2] = '*';    
        arr[x + 2][y - 1] = '*';
        arr[x + 2][y] = '*';
        arr[x + 2][y + 1] = '*';
        arr[x + 2][y + 2] = '*';
    } 
    else {
        solve(x, y, (n / 2));
        solve(x + (n / 2), y - (n / 2), (n / 2));
        solve(x + (n / 2), y + (n / 2), (n / 2));
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N * 2; j++)
            arr[i][j] = ' ';

    solve(0, N - 1, N);
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N * 2; j++)
            cout << arr[i][j];   
        cout << endl;
    }
    return 0;
}