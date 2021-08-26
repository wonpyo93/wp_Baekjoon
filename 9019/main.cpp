#include<iostream>
#include<string.h>
#include<queue>
#define MAX 10001
using namespace std;

int A, B, T, tmp;
bool visited[MAX];
 
string BFS(int a) {
    queue<pair<int, string>> Q;
    Q.push(make_pair(a, ""));
    visited[a] = true;
 
    while(Q.empty() == 0) {
        int x = Q.front().first;
        string str = Q.front().second;
        Q.pop();
 
        if(x == B)
            return str;
        
        tmp = x * 2;
        if(tmp > 9999)
            tmp = tmp % 10000;
        if(visited[tmp] == false) {
            visited[tmp] = true;
            Q.push(make_pair(tmp, str + "D"));
        }

        tmp = x - 1;
        if(tmp < 0) tmp = 9999;
        if(visited[tmp] == false) {
            visited[tmp] = true;
            Q.push(make_pair(tmp, str + "S"));
        }
 
        tmp = (x % 1000) * 10 + (x / 1000);
        if(visited[tmp] == false) {
            visited[tmp] = true;
            Q.push(make_pair(tmp, str + "L"));
        }
 
        tmp = (x % 10) * 1000 + (x / 10);
        if(visited[tmp] == false) {
            visited[tmp] = true;
            Q.push(make_pair(tmp, str + "R"));
        }
    }
    return "";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for(int t = 0; t < T; t++) {
        memset(visited, false, sizeof(visited));
        cin >> A >> B;
        cout << BFS(A) << endl;
    }
    return 0;
}