#include <iostream>
using namespace std;


int T, N, M;
long long ans;

long long factorial(int a) {
    long long fact = 1;
    for(int i = 1; i <= a; i ++) {
        fact = fact * i;
    }
    return fact;
}

long long factorial_subtracted(int a, int b) {
    long long fact = 1;
    for(int i = a + 1; i <= b; i++) {
        fact = fact * i;
    }
    return fact;
}

int main() {
    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> N >> M;
        int bigger = (N > (M - N)) ? N : M - N;
        int smaller = (N > (M - N)) ? M - N : N;

        ans = factorial_subtracted(bigger, M) / factorial(smaller);
        cout << ans << endl;
    }
    return 0;
}