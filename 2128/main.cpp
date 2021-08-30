#include <iostream>
#include <vector>
using namespace std;

int N, D, K, count, prob, ans;
bool visited[16];
vector<int> v[1000];

int solve() {
	int a = 0;
	for(int i = 0; i < N; i++) {
		bool flag = true;
		for(int j = 0; j < v[i].size(); j++) {
			if (!visited[v[i][j]]) {
				flag = false;
				break;
			}            
        }
		if(flag)
            a++;
	}
	return a;
}

void func(int a, int r) {
	if (r == 0)
		ans = max(ans, solve());
	else if(a < r)
        return;
	else {
		visited[a] = true;
		func(a - 1, r - 1);

		visited[a] = false;
		func(a - 1, r);
	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ans = 0;
	cin >> N >> D >> K;
	for(int i = 0; i < N; i++) {
		cin >> count;
		for(int j = 0; j < count; j++) {
			cin >> prob;
			v[i].push_back(prob);
		}
	}
	func(D, K);
	cout << ans;
	return 0;
}