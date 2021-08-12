#include <iostream>
using namespace std;

int main() {
    int n, m, x1, y1, x2, y2, count;
    cin >> n;
    for(int i = 0; i < n; i++) {
        count = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> m;
        int x3, y3, r;
        for(int i = 0; i < m; i++) {
            cin >> x3 >> y3 >> r;
            int d1 = ((x3 - x1)*(x3 - x1)) + ((y3 - y1)*(y3 - y1));
            int d2 = ((x3 - x2)*(x3 - x2)) + ((y3 - y2)*(y3 - y2));
            int rSquare = r*r;
            //두 점 모두 밖은 셀 필요 없음
            //두 점 모두 안도 셀 필요 없음

            //한 점만 안
            if((d1 > rSquare && d2 < rSquare) || (d1 < rSquare && d2 > rSquare))
                count++;
        }
        cout << count << endl;
    }
    return 0;
}