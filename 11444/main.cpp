#include<iostream>
#include<vector>
#define MOD 1000000007
using ll = long long;
using namespace std;
typedef vector<vector<ll>> matrix;
ll N;

matrix matmul(matrix& a, matrix& b) {
	matrix temp(2, vector<ll>(2));
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++)
				temp[i][j] += a[i][k] * b[k][j];
			temp[i][j] %= MOD;
		}
	return temp;
}

int main() {
	cin >> N;
	matrix ans = 	{{1, 0}, {0, 1}};
	matrix a = 		{{1, 1}, {1, 0}};

	while (N > 0) {
		if (N % 2 == 1)
			ans = matmul(ans, a);
		a = matmul(a, a);
		N /= 2;
	}
	cout << ans[0][1];
}