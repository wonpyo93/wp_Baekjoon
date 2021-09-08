#include <iostream>
#include<cstring>
#include <algorithm>
using namespace std;
#define INF 999999999;

int N, M, t, key[] = {1,1,1,1,1,1,1,1,1,1}, ans;

void recursiveFunc(string num) {
    for(int i = 0; i < 10; i++) {
	    if(key[i]) {
	        string temp = num + to_string(i);
            int compare = abs(N - stoi(temp)) + temp.length();
	        ans = min(ans, compare);
    	    if(temp.length() < 6)
	    	    recursiveFunc(temp);
	    }
    }
}

int main() {
    cin >> N;
    cin >> M;
    int temp = M;
    ans = INF;
    ans = min(ans, abs(N - 100));
    for(int i = 0; i < M; i++) {
        cin >> t;
        key[t] = 0;   
    }
    
    if(M < 10)
	    recursiveFunc("");

    cout << ans;   
}