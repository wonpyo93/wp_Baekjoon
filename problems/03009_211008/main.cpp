#include <iostream>
#define endl '\n'
using namespace std;

int arr[3][2], x, y;

int main() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++)
            cin >> arr[i][j];

    x = arr[0][0];
    y = arr[0][1];

    x = arr[1][0] == x ? arr[2][0] : (arr[1][0] == arr[2][0] ? x : arr[1][0]);
    y = arr[1][1] == y ? arr[2][1] : (arr[1][1] == arr[2][1] ? y : arr[1][1]);
    
    cout << x << ' ' << y;
    return 0;
}
