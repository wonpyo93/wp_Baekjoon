#include <iostream>
#include <string.h>
#define MOD 1000
using namespace std;

int N;
long long A;

struct MAT {
    int arr[6][6];
};
MAT ans, mat;

MAT matmul(MAT a, MAT b) {
    MAT temp;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) {
            temp.arr[i][j] = 0;
            for(int k = 0; k < N; k++)
                temp.arr[i][j] += a.arr[i][k] * b.arr[k][j];
            temp.arr[i][j] = temp.arr[i][j] % MOD;
        }
    
    // //checking
    // for(int i = 0; i < N; i++) {
    //     for(int j = 0; j < N; j++) {
    //         cout << temp.arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    return temp;
}

int main() {
    cin >> N >> A;
    
    //receive input
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            cin >> mat.arr[i][j];
        ans.arr[i][i] = 1;
    }

    //computation part
    while(A > 0) {
        if (A % 2 == 1)
            ans = matmul(ans, mat);
        A /= 2;
        mat = matmul(mat, mat);
    }
    
    //print answer
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << ans.arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}