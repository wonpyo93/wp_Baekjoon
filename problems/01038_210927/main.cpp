#include <iostream>
#include <queue>
#define ll long long
#define endl '\n'
using namespace std;

int N;
int idx = 9;
queue<ll> q;
ll descending[1000001];

void preCalculate() {
    while(idx <= N) {
        if (q.empty()) return;

        ll descendingNum = q.front();
        q.pop();

        int lastNum = descendingNum % 10;

        for(int i = 0; i < lastNum; i++) {
            q.push(descendingNum * 10 + i);
            idx++;
            descending[idx] = descendingNum * 10 + i;
        }
    }
}

int main(void) {
    cin >> N;
    for(int i = 1; i <= 9; i++) {
        q.push(i);
        descending[i] = i;
    }
    preCalculate();

    if(!descending[N] && N)
        cout << -1 << endl;
    else
        cout << descending[N] << endl;
    return 0;
}