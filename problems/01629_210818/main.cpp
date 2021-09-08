#include <iostream>
using namespace std; 

long long A, B, C, ans;

long long func(int a, int b, int c) {
    if(b > 1) {
        long long ans = func(a, b / 2, c);
        if(b % 2 != 0)
            return ((ans * ans) % c * a) % c;
        else
            return (ans * ans) % c;
    }
    else return a;
}
 
int main() {
    cin >> A >> B >> C;
 
    ans = func(A % C, B, C);
    cout << ans;
    return 0;
}