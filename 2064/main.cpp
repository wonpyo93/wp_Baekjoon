#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

int N, target, isAt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    string ip;
    
    int inputIp[N];

    for(int i = 0; i < N; i++) {
        cin >> ip;
        istringstream ss(ip);
        string tmp;
        while(getline(ss,tmp,'.')) {
            inputIp[i] <<= 8;
            inputIp[i] |= stoi(tmp);
        }
    }
    
    int subnet = 0;
    int netAddr = 0;
    for(int i = 31; i >= 0; i--) {
        
        int bit = 1 << i;
        bool isContinue = true;
        for(int r=1; r<N; r++){
            if((inputIp[0] & bit) != (inputIp[r] & bit)){
                isContinue = false;
                break;
            }
        }
        if(!isContinue)
            break;
        else
            subnet |= bit;
    }
    target = subnet & inputIp[0];
    isAt = 24;
    for(int i = 0; i < 4; i++) {
        cout << ((target >> isAt) & (1 << 8) - 1);
        if(i != 3)
            cout << '.';
        isAt -= 8;
    }
    cout << endl;

    target = subnet;
    isAt = 24;
    for(int i = 0; i < 4; i++) {
        cout << ((target >> isAt) & (1 << 8) - 1);
        if(i != 3)
            cout << '.';
        isAt -= 8;
    }
    cout << endl;
    return 0;
}