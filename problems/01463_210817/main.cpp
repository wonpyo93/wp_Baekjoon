#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std; 
#define MAX 11111111

int N, cost[MAX];

int check(int a, int b) {
    if(a == 0)
        return b;
    else
        return min(a, b);
}

int main() {
    memset(cost, 0, sizeof(cost));
    cin >> N;
    for(int i = 1; i <= N; i++) {
        if(i <= N - 1)
            cost[i + 1] = check(cost[i + 1], cost[i] + 1);
        if(i <= N / 2)
            cost[i * 2] = check(cost[i * 2], cost[i] + 1);
        if(i <= N / 3)
            cost[i * 3] = check(cost[i * 3], cost[i] + 1);
    }
    cout << cost[N];
    return 0;
}