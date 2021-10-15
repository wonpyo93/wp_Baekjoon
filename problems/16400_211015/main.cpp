#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define MOD 123456789
using namespace std;

int N, ans;
int arr[40001], factors[40001];
vector<int> p;

void findPrime() {
    factors[0] = factors[1] = -1;
    for (int i = 2; i < 40001; i++)
        factors[i] = i;

    for(int i = 2; i < 40001; i++)
        if(factors[i] == i) {
            for (int j = i * i; j < 40001; j += i)
                if (factors[j] == j)
                    factors[j] = i;
        }

    for(int i = 2; i < 40001; i++)
        if(factors[i] == i)
            p.push_back(i);
}

// 숫자 N (2 <= N <= 40000) 소수의 합으로 나타낼 수 있는 최대 개수를 출력하는 문제.
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    ans = 0;

    findPrime();
    arr[0] = 1;
    
    for (int i = 0; i < p.size(); i++)
        for (int j = p[i]; j <= N; j++) {
            arr[j] = (arr[j] + arr[j - p[i]]) % MOD;
            arr[j] %= MOD;
        }
    
    cout << arr[N] << endl;

    return 0;
}