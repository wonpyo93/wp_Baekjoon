#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int T, sz, start, finish;
bool rev, done;

int main() {
	cin >> T;
	for(int t = 0; t < T; t++) {
        string str, arr, tmp;

        //receive basic input
		cin >> str >> sz >> arr;
        vector<int> vec;

        //receive vector input
		for(int i = 0; i < arr.length(); i++) {
			if('0' <= arr[i] && arr[i] <= '9')
				tmp += arr[i];
			else {
				if(tmp.length() != 0) {
					vec.push_back(stoi(tmp));
					tmp.clear();
				}
			}
		}

        //initialize
        done = false;
		rev = false;
		start = 0;
        finish = sz;

        //func
		for(int i = 0; i < str.length(); i++) {
			if(str[i] == 'R')
				rev = !(rev);
			else {
				if(rev) finish--;
				else start++;
				if(start > finish) {
					done = true;
					break;
				}
			}
		}

        //print answer
		if(done)
            cout << "error" << endl;
		else{
            cout << "[";
			if(rev) {
				for(int i = finish - 1; i >= start; i--) {
                    cout << vec[i];
					if(i != start)
                        cout << ",";
				}
			}
			else {
				for(int i = start; i < finish; i++) {
                    cout << vec[i];
					if (i != finish - 1)
                        cout << ",";
				}
			}
            cout << "]" << endl;
		}
	}
    return 0;
}