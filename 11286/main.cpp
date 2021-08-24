#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, temp;
priority_queue<int, vector<int>, greater<int>> Q_1; // 이건 올림차순.
priority_queue<int> Q_2; //이건 내림차순.

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        if(temp == 0) {
            if(Q_1.size() > 0 && Q_2.size() > 0) {
                if(abs(Q_1.top()) < abs(Q_2.top())) { //+쪽에서 -보다 더 작은 절대값이 나오면
                    cout << Q_1.top() << '\n';
                    Q_1.pop();
                }
                else { //-쪽에서 +보다 더 작은 절대값이 나오면 (그리고, 둘다 같을 경우도 -쪽에서 더 작은 아이로 판별되기 때문에 묶었다)
                    cout << Q_2.top() << '\n';
                    Q_2.pop();
                }

            }
            else if(Q_1.size() > 0 && Q_2.size() == 0) {
                cout << Q_1.top() << '\n';
                Q_1.pop();
            }
            else if(Q_1.size() == 0 && Q_2.size() > 0) {
                cout << Q_2.top() << '\n';
                Q_2.pop();
            }
            else { //(Q_1.size() == 0 && Q_2.size() == 0)
                cout << 0 << '\n';
            }
        }
        else if(temp > 0) { //0보다 크면 올림차순
            Q_1.push(temp);
        }
        else { //0 보다 작으면 내림차순
            Q_2.push(temp);
        }
    }
	return 0;
}