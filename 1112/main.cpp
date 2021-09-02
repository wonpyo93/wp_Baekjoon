#include <iostream>
#include <algorithm>
using namespace std;

int N, b, m;

int mod(int N, int b) {
    int r = N % abs(b);
    if(r < 0) r += abs(b);
    return r;
}

int base(int N, int b, char r[]) {
    int na = b > 0 ? abs(N) : N, t;
    int c = 0;
    while(na) {
        t = mod(na, b);
        na = (na - t) / b;
        r[c++] = t + '0';
    }
    if(!c)
        r[c++] = '0';
    r[c] = 0;
    return (b > 0 && N < 0);
}

void print(char r[], int m) {
    int i;
    if(m)
        putchar('-');
    for(i = 1; r[i] ; i++);
    for(i-- ; i >= 0; i--)
        putchar(r[i]);
    putchar('\n');
}

int main() {
    char r[64];
    cin >> N >> b;
    m = base(N, b, r);
    print(r, m);
}