#include <iostream>
#include <algorithm>
#include <string.h>
#define endl '\n'
using namespace std;

string str;
int sz, zeroCnt, oneCnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //initialize
    zeroCnt = 0;
    oneCnt = 0;

    //get input and input size
    cin >> str;
    sz = str.length();

    //find exception case
    if(sz == 0 || sz == 1) {
        cout << 0;
        return 0;
    }

    //find 0's and 1's consecutive length size
    char prev = str[0];
    if(prev == '0') zeroCnt++;
    else oneCnt++;
    for(int i = 1; i < sz; i++) {
        if(str[i] == '0') {
            if(prev == '0')
                continue;
            else { //prev == '1'
                prev = '0';
                zeroCnt++;
            }
        }
        else { //str[i] == '1'
            if(prev == '1')
                continue;
            else { //prev == '0'
                prev = '1';
                oneCnt++;
            }
        }
    }
    cout << min(zeroCnt, oneCnt);
    return 0;
}