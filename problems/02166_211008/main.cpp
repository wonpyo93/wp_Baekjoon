#include <iostream>
#include <math.h>
#define endl '\n'
using namespace std;

double x[10001];
double y[10001];
int N;
double ans;

double ccw(int a, int b, int c) {
	double tmp1[2] = {y[b] - y[a], x[b] - x[a]};
	double tmp2[2] = {y[c] - y[a], x[c] - x[a]};
	double tmp3 = tmp1[0] * tmp2[1] - tmp1[1] * tmp2[0];
	return tmp3 / 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N;

    ans = 0;

	for (int i = 0; i < N; i++)
		cin >> x[i] >> y[i];

	for (int i = 1; i < N - 1; i++)
		ans += ccw(0, i, i + 1);

	cout.precision(1);
	cout << fixed;
	cout << abs(ans);

	return 0;
}