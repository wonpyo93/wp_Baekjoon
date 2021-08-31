#include <iostream>
using namespace std;

int N, L;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> L;

    while(N >= (L * (L - 1) / 2) && L < 101) {
        if((N - (L * (L - 1) / 2)) % L == 0) {
            for(int j = 0; j < L; j++)
                cout << ((N - (L * (L - 1) / 2)) / L) + j << ' ';
            return 0;
        }
        L++;
    }
    cout << -1 << endl;
    return 0;
}