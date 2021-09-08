#include <iostream>
#include <string>
using namespace std;

int N, M, ans, o_num;
string S;

int main() {
	cin >> N >> M >> S;
	for (int i = 0; i < M; i++) {
		if(S[i] == 'O')
            continue;
		o_num = 0;
		while (S[i + 1] == 'O' && S[i + 2] == 'I') {
			o_num++;
			i = i + 2;
			if(o_num == N) {
				o_num--;
				ans++;
			}
		}
	}
	cout << ans;
}