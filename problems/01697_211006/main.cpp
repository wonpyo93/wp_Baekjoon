#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

int N, K, p, d;
bool visited[100001] = {0,};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> K;

    queue<pair<int,int>> q;
    q.push(pair<int, int>(N, 0));

    while(!q.empty()) {
        p = q.front().first;
        d = q.front().second;

        if(p == K)
            break;

        q.pop();

        visited[p] = true;

        if(p - 1 >= 0 && !visited[p - 1])
            q.push(pair<int,int>(p - 1, d + 1));

        if(p + 1 <= 100000 && !visited[p+1])
            q.push(pair<int,int>(p + 1, d + 1));

        if(p * 2 <= 100000 && !visited[p * 2])
            q.push(pair<int,int>(p * 2, d + 1));
    }

    cout << q.front().second << endl;
    return 0;
}