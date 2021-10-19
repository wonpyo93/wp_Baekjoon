#include <iostream>
#include <string.h>
#include <algorithm>
#define endl '\n'
using namespace std;

int T;

bool cmp(pair<int,char> a, pair<int,char> b) {
    return a.first > b.first;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> T;
    cin.ignore();
    while(T--) {
        string str;
        getline(cin, str);
        
        pair<int, char> arr[26] = { {0, ' '} };
        
        for(int i = 0; i < str.length(); i++) {
            if(isspace(str[i]))
                continue;
            arr[str[i] - 'a'] = { arr[str[i] - 'a'].first+1,str[i] };
        }
        
        sort(arr, arr + 26, cmp);
        
        if(arr[0].first != arr[1].first)
            cout << arr[0].second <<  endl;
        else
            cout << "?" << endl;
    }
    return 0;
}