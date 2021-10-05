#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int N;
int arr[100][100];

void func(int sz, int x, int y) {
    if (sz == 1) {
        cout << arr[y][x];
        return;
    }
    bool flag = true;

    for(int i = y; i < y + sz; i++) {
        if (!flag) break;
        for (int j = x; j < x + sz; j++) {
            if (arr[y][x] != arr[i][j]) {
                flag = false;
                break;
            }
        }
    }

    if(flag) {
        cout << arr[y][x];
        return;
    }

    int tmp = sz / 2;

    cout << "(";
    func(tmp, x, y);
    func(tmp, x + tmp, y);
    func(tmp, x, y + tmp);
    func(tmp, x + tmp, y + tmp);
    cout << ")";
}

int main() {
    cin >> N;
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%1d", &arr[i][j]);

    func(N, 0, 0);
    cout << endl;
    return 0;
}