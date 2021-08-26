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

	for(int repLen = 1; repLen <= 60; repLen++) {
        repeat = true;
		string tmp_str = str.substr(0, repLen);
        int idx = repLen;
        while(repLen + idx <= 120) {
            if(str.substr(idx, repLen) != tmp_str) {
                repeat = false;
				break;
			}
            idx += repLen;
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