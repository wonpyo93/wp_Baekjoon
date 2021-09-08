#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

ll w, h, f, c, x1, y1, x2, y2;

int main() {
	cin >> w >> h >> f >> c >> x1 >> y1 >> x2 >> y2;
	ll colored = (x2 - x1) * (y2 - y1) * (c + 1);
	if(f <= w / 2) {
		if(f <= x1)
			cout << w * h - colored;
		else
			cout << w * h - (colored + (min(f, x2) - x1) * (y2 - y1) * (c + 1));
	} 
	else {
		if(w <= x1 + f)
			cout << w * h - colored;
		else
			cout << w * h - (colored + (min(w, f + x2) - (f + x1)) * (y2 - y1) * (c + 1));
	}
    return 0;
}