#include <iostream>
#include <string.h>
#define endl '\n'
using namespace std;

string str1, str2, str3;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> str1 >> str2;
    str3 = "";

    for(int i = 0; i < str1.length(); i++) {
        if(str1[i] - '0' >= 0 && str1[i] - '0' <= 9)
            continue;
        str3.push_back(str1[i]);
    }

    if(str3.find(str2) == string::npos)
        cout << 0;
    else
        cout << 1;
        
    return 0;
}