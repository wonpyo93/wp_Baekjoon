#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"
#define MAX 10001
using namespace std;

int node, edge, ans;
int Parent[MAX];
vector<pair<int, pair<int, int>>> V;

int parentFind(int x) {
    if (Parent[x] == x)
        return x;
    else
        return Parent[x] = parentFind(Parent[x]);
}
 
void parentCombine(int x, int y) {
    x = parentFind(x);
    y = parentFind(y);
    if (x != y)
        Parent[y] = x;
}
 
bool parentCheck(int x, int y) {
    x = parentFind(x);
    y = parentFind(y);
 
    if(x == y)
        return true;
    else
        return false;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> node >> edge;
    for(int i = 0; i < edge; i++) {
        int From, To, Cost;
        cin >> From >> To >> Cost;
        V.push_back(make_pair(Cost, make_pair(From, To)));
    }
 
    sort(V.begin(), V.end());
    
    for(int i = 1; i <= node; i++)
        Parent[i] = i;
 
    for(int i = 0; i < edge; i++) {
        if(parentCheck(V[i].second.first, V[i].second.second) == false) {
            parentCombine(V[i].second.first, V[i].second.second);
            ans = ans + V[i].first;
        }
    }

    cout << ans;
    return 0;
}