#include <iostream>
#define endl '\n'
using namespace std;

int T, N, M, ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    
    for(int t = 0; t < T; t++) {
        cin >> N >> M;
        ans = 0;
        
        for(int i = 1; i < N; i++) {
            for(int j = i + 1; j < N; j++) {
                int temp = i * i + j * j + M;
                if (temp % (i * j) == 0)
                    ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}