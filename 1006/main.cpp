#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T, N, W;
    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> N, W;
        int arr[2][N];
        for(int i = 0; i < N; i++)
            cin >> arr[0][i];
        for(int i = 0; i < N; i++)
            cin >> arr[1][i];
    }
    
    return 0;
}