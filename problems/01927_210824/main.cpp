#include <iostream>
#include <queue>
using namespace std;

int N, temp;
priority_queue<int, vector<int>, greater<int>> Q;

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        if(temp == 0) {
            if(Q.size() > 0) {
                cout << Q.top() << '\n';
                Q.pop();
            }
            else
                cout << 0 << '\n';
        }
        else Q.push(temp);
    }
	return 0;
}