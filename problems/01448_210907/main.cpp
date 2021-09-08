#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

int N;
int s_1, s_2, s_3;

bool compare(int a, int b){
    return a > b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    s_1 = 0;
    s_2 = 1;
    s_3 = 2;
    cin >> N;
    int arr[N];

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N, compare);

    while(true) {
        if(arr[s_1] < arr[s_2] + arr[s_3]){
            cout << arr[s_1] + arr[s_2] + arr[s_3] << endl;
            break;
        }
        s_1++;
        s_2++;
        s_3++;
        if(s_3 >= N) {
            cout << -1;
            break;
        }
    }
    return 0;
}