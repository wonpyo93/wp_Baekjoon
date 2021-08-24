#include <iostream>
using namespace std;

int N, M, arr[100001], toFind[100001][2], temp;

int main() {
    //initialize the first array with 0
    arr[0] = 0;
    
    ios::sync_with_stdio(0);
	cin.tie(0);

    //receive input
    cin >> N >> M;
    for(int i = 1; i < N + 1; i++) {
        cin >> temp;
        arr[i] = arr[i - 1] + temp; //directly make the array the sum from start to i
    }
    
    //receive input and print answer
    for(int i = 0; i < M; i++) {
        cin >> toFind[i][0] >> toFind[i][1];
        cout << arr[toFind[i][1]] - arr[toFind[i][0] - 1] << '\n';
    }
    return 0;
}