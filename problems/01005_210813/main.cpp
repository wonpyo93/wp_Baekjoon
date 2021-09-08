#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int T, n, k, w, a, b;
    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> n >> k;
        int c[n+1], d[n+1], td[n+1];
        vector<int> l[n+1];
        for(int i = 1; i < n+1; i++) {
            cin >> d[i];
            td[i] = 0;
            c[i] = 0;
        }
        for(int i = 0; i < k; i++) {
            cin >> a >> b;
            l[a].push_back(b);
            c[b]++;
        }
        cin >> w;
        queue<int> q;
        for(int i = 1; i < n+1; i++)
            if(c[i] == 0)
                q.push(i);
        
        while(c[w] > 0) {
            int temp = q.front();
            q.pop();
            for(int j : l[temp]) {
                if((td[temp] + d[temp]) > td[j])
                    td[j] = td[temp] + d[temp];
                c[j]--;
                if(c[j] == 0)
                    q.push(j);
            }
        }
        cout << td[w] + d[w] << endl;
    }
    return 0;
}