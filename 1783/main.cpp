#include <iostream> 
#include <algorithm>
#define endl '\n'
using namespace std;

int N, M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    if(N == 1)
        cout << 1;
    else if(N == 2)
        cout << min(4, (M + 1) / 2);
    else if(M < 7)
        cout << min(4, M);
    else
        cout << M - 2;
    
    return 0;
}
