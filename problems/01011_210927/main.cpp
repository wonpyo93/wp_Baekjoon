#include <iostream>
#include <cmath>
#define ll long long
#define endl '\n'
using namespace std;

int T, spd, cnt, tmp;
ll a, b, c, rem, ans;
int main() {
    cin >> T;
    
    for(int i = 0; i < T; i++) {
        cin >> a >> c;
        b = c - a;
        spd = sqrt(b);
        int tmp = pow(spd, 2);
        cnt = 2 * spd - 1;
        rem = (ll)ceil(((double)b - (double)tmp) / (double)spd);
        ans = cnt + rem;
        cout << ans << endl;
    }
}