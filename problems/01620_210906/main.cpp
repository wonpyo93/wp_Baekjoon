#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#define endl '\n'
using namespace std;  

int N, M, idx;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    map<string, int> pockemonMap;
    string str[100001];
    cin >> N >> M;
    
    for(int n = 0; n < N; n++) {
        string pokemon;
        cin >> pokemon;
        pockemonMap.insert({pokemon, n + 1});
        str[n + 1] = pokemon;
    }
    
    for(int m = 0; m < M; m++) {
        char order[21];
        cin >> order;
        
        if('0' <= order[0] && order[0] <= '9') {
            idx = atoi(order);
            cout << str[idx] << endl;
        }
        else 
            cout << pockemonMap[string(order)] << endl;
    }
    return 0;
}