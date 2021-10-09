#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

int x1, y1, p1, q1, x2, y2, p2, q2;
int xr, xl, yb, yt, x_diff, y_diff;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for(int i = 0; i < 4; i++) {
        cin >> x1 >> y1 >> p1 >> q1 >> x2 >> y2 >> p2 >> q2;
        
        xl = max(x1, x2);
        xr = min(p1, p2);
        yb = max(y1, y2); 
        yt = min(q1, q2);
        x_diff = xr - xl;
        y_diff = yt - yb;
        
        if(x_diff > 0 && y_diff > 0)
            cout << 'a' << endl;
        else if(x_diff < 0 || y_diff < 0)
            cout << 'd' << endl;
        else if(x_diff == 0 && y_diff == 0)
            cout << 'c' << endl;
        else cout << 'b' << endl;
    }
    return 0;
}