#include <iostream>
using namespace std;

int main(){
    int a, b, c0, c1, d0, d1, e;
    cin >> a;
    for(int i = 0; i < a; i++) {
        cin >> b;
        c0 = 1;
        c1 = 0;
        d0 = 0;
        d1 = 1;
        if(b == 0)
            cout << 1 << " " << 0 << endl;
        else if(b == 1)
            cout << 0 << " " << 1 << endl;
        else{
            for(int j = 0; j < b - 1; j++){
                int temp = c0 + c1;
                c0 = c1;
                c1 = temp;
                temp = d0 + d1;
                d0 = d1;
                d1 = temp;
            }
            cout << c1 << " " << d1 << endl;
        }
    }
}