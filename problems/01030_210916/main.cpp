#include <iostream>
using namespace std;

int S, N, K, r1, r2, c1, c2;

int func(int len, int x, int y) {
	if(len == 1)
        return 0;
	int tmp = len / N;
	if (x >= tmp * (N - K) / 2 && 
            x < tmp * (N + K) / 2 &&
                y >= tmp * (N - K) / 2 &&
                    y < tmp * (N + K) / 2) {
		return 1;
	}
	return func(tmp, x % tmp, y % tmp);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> S >> N >> K >> r1 >> r2 >> c1 >> c2;
    
	if (S == 0) {
		cout << 0;
		return 0;
	}
	
	int len = 1;

	while(S--)
        len *= N;
	for(int i = r1; i <= r2; i++) {
		for(int j = c1; j <= c2; j++) {
            cout << func(len, i, j);
		}
		cout << endl;
	}
}