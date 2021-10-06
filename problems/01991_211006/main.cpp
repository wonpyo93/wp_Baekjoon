#include <iostream>
#include <string.h>
#define endl '\n'

using namespace std;

int N;
char x, y, z;
char arr[26][2];

void pre(char a) {
    if(a == '.')
        return;
    cout << a;
    pre(arr[a - 'A'][0]);
    pre(arr[a - 'A'][1]);
}

void in(char a) {
    if(a == '.')
        return;
    in(arr[a - 'A'][0]);
    cout << a;
    in(arr[a - 'A'][1]);
}

void post(char a) {
    if(a == '.')
        return;
    post(arr[a - 'A'][0]);
    post(arr[a - 'A'][1]);
    cout << a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> x >> y >> z;
        arr[x - 'A'][0] = y;
        arr[x - 'A'][1] = z;
    }
    pre('A');
    cout << endl;
    in('A');
    cout << endl;
    post('A');
    return 0;
}
