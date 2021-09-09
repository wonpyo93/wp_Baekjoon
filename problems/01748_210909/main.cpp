#include <iostream>
#include <math.h>
#include <string.h>
#define endl '\n'
#define ll long long
#define lld long double
using namespace std;

ll N, nSquared;
int sz, cnt;
char str[100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

	char str[15];
	sprintf(str, "%ld", N);
	sz = strlen(str);

    nSquared = N - pow((lld) 10L, sz - 1) + 1;
	cnt = nSquared * sz;

	for(int i = 1; i < sz; i++)
		cnt += 9 * pow((lld) 10L, sz - i - 1) * (sz - i);

    cout << cnt;
	return 0;
}