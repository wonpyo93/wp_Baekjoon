#include <iostream>
#include <string.h>
using namespace std;

unsigned long long A, B, tmp;
bool repeat;
string str;

int func() {
    if(A == 0) {
        cout << '-';
        return 0;
    }
	if(A == B) {
        cout << '*';
        return 0;
    }
    repeat = false;
    tmp = A;
	while(tmp != 0 && str.length() < 120) {
		if(A == tmp)
			repeat = true;

		tmp += tmp;
		if(tmp >= B) {
			str += '*';
			tmp -= B;
		}
		else
			str += '-';

	}

	if(repeat == false || str.length() < 120) {
		cout << -1 << endl;
		return 0;
	}

	for(int len = 1; len <= 60; len++) {
        repeat = true;
		string tmp_str = str.substr(0, len);
        int idx = len;
        while(len + idx <= 120) {
            if(str.substr(idx, len) != tmp_str) {
                repeat = false;
				break;
			}
            idx += len;
        }

        if(repeat == true) {
            cout << tmp_str;
            return 0;
        }
	}
	cout << -1 << endl;
    return 0;
}

int main() {
	cin >> A >> B;
    func();
	return 0;
}