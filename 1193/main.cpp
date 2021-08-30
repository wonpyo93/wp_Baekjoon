#include <iostream>
using namespace std;

int X;
int x, y, curr, last;

int main() {
    bool flag = true;
    x = y = last = curr = 1;

    cin >> X;
    while(true) {
        for(int i = 0; i < last; i++) {
            if (X == curr)
                goto exit;
            else
                curr++;
            
            if(i + 1 != last) {
                if(flag) {
                    x++;
                    y--;
                }
                else {
                    x--;
                    y++;
                }
            }
        }
        if (flag)
            x++;
        else
            y++;
        
        last++;
        flag = !flag;
    }
    
exit:
    cout << y << '/' << x;
    return 0;
}