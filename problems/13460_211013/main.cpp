#include <iostream>
#include <algorithm>
#include <math.h>
#define endl '\n'
using namespace std;
 
int N, M, ans = 987654321;
char arr[10][10];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
pair<int, int> r, b;

int move(int x, int y, int xx, int yy) {
    return abs(x - xx) + abs(y - yy);
}
 
int inv(int a) {
    if(a == 0)
        return 1;
    else if(a == 1)
        return 0;
    else if(a == 2)
        return 3;
    else if(a == 3)
        return 2;
}
 
void func(int Rx, int Ry, int Bx, int By, int cnt, int dir) {
    if (cnt >= ans)
        return;
        
    if (cnt > 10)
        return;
 
    bool flag_r = false;
    bool flag_b = false;
 
    int nRx = Rx + dx[dir];
    int nRy = Ry + dy[dir];

    while(true) {
        if(arr[nRx][nRy] == '#') break;
        if(arr[nRx][nRy] == 'O') {
            flag_r = true;
            break;
        }
        nRx = nRx + dx[dir];
        nRy = nRy + dy[dir];
    }

    nRx = nRx - dx[dir];
    nRy = nRy - dy[dir];

    int nBx = Bx + dx[dir];
    int nBy = By + dy[dir];

    while(true) {
        if (arr[nBx][nBy] == '#')
            break;

        if (arr[nBx][nBy] == 'O') {
            flag_b = true;
            break;
        }

        nBx = nBx + dx[dir];
        nBy = nBy + dy[dir];
    }
    nBx = nBx - dx[dir];
    nBy = nBy - dy[dir];

    if(flag_b == true)
        return;
    else {
        if(flag_r == true) {
            ans = min(ans, cnt);
            return;
        }
    }

    if(nRx == nBx && nRy == nBy) {
        int rTmp = move(Rx, Ry, nRx, nRy);
        int bTmp = move(Bx, By, nBx, nBy);

        if (rTmp > bTmp) {
            nRx = nRx - dx[dir];
            nRy = nRy - dy[dir];
        }
        else {
            nBx = nBx - dx[dir];
            nBy = nBy - dy[dir];
        }
    }

    for(int i = 0; i < 4; i++) {
        if(i == dir)
            continue;
        if(i == inv(dir))
            continue;
 
        func(nRx, nRy, nBx, nBy, cnt + 1, i);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 'R') {
                r.first = i;
                r.second = j;
                arr[i][j] = '.';
            }
            else if(arr[i][j] == 'B') {
                b.first = i;
                b.second = j;
                arr[i][j] = '.';
            }
        }
    }

    for(int i = 0; i < 4; i++) {
        int x = r.first;
        int y = r.second;
        
        int xx = b.first;
        int yy = b.second;
 
        func(x, y, xx, yy, 1, i);
    }

    if (ans > 10 || ans == 987654321)
        ans = -1;
    cout << ans << endl;

    return 0;
}