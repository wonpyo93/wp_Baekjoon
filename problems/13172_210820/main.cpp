#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ull;
int M;
ull ans;
vector<ull> N, S;

ull pow(ull a, int b) {
    ull z;
    if (b == 1)
        return a;
    z = pow(a, b / 2);
    z = z * z;
    z %= 1000000007;
    if (b % 2) {
        z *= a;
        z %= 1000000007;
    }
    return z;
}

int main() {
    ans = 0;
    cin >> M;
    N.resize(M);
    S.resize(M);

    for (int i = 0; i < M; i++) {
        cin >> N[i] >> S[i];
        ans += S[i] * pow(N[i], 1000000005);
        ans %= 1000000007;
    }
    cout << ans;
}