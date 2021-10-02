#include <iostream>
#define endl '\n'
#define MAX 100001
using namespace std;

int N;
int choice[3][MAX];

int func() {
    choice[0][1] = 1;
    choice[1][1] = 1;
    choice[2][1] = 1;

    for(int i = 2; i <= N; i++) {
            choice[0][i] = (choice[0][i - 1] + choice[1][i - 1] + choice[2][i - 1]) % 9901;
            choice[1][i] = (choice[0][i - 1] + choice[2][i - 1]) % 9901;
            choice[2][i] = (choice[0][i - 1] + choice[1][i - 1]) % 9901;
    }
    return (choice[0][N] + choice[1][N] + choice[2][N]) % 9901;
}

int main() {
    cin >> N;
    if(N < 1 || N > MAX - 1)
        return 0;
    cout << func() << endl;
    return 0;
}