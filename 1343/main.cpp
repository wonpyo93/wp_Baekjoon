#include <iostream>
#include <string.h>
#define endl '\n'
using namespace std;

int cnt;
string str;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cnt = 0;
    cin >> str;
    
    for(int i = 0; i < str.length(); i++) {
        cnt++;
        if(str[i] == '.') {
            cnt--;
            if(cnt == 2) {
                for(int j = 1; j <= 2; j++)
                    str[i - j] = 'B';
                cnt = 0;
            }
            cnt=0;
        }
        else {
            if(cnt == 4) {
                for(int j = 0; j < 4; j++)
                    str[i - j] = 'A';
                cnt = 0;
            }
            if(i == str.length() - 1) {
                if(cnt == 2) {
                    for(int j = 0; j < 2; j++)
                        str[i - j] = 'B';
                    cnt=0;
                }
            }
        }
    }
    if(str.find('X') != string::npos)
        cout << -1;
    else
        cout << str;
}