#include <iostream>
using namespace std;

int D, N, x;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	while(cin >> N) {
        x = 1;
        D = 1;
		while (x % N != 0) {
			x %= N;
			x = 10 * x + 1;
			D++;
		}
		cout << D << endl;
	}

	return 0;
}