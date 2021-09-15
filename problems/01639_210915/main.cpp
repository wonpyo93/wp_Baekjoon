#include <iostream>
#include <string.h>
using namespace std;

string str;
int start, finish, mid, tmp1, tmp2, l, r;
int arr[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin >> str;

	for(int i = 0; i < str.size(); i++)
		arr[i] = str[i] - 48;
	
    if(str.size() % 2 == 0) {
        finish = str.size() + 2;
    }
    else {
        finish = str.size() + 1;
    }
	
	while(finish > 2) {
		start = 0; finish -= 2;
		tmp1 = start;
        tmp2 = finish;
		while(tmp2 <= str.size()) {
			mid = (tmp1 + tmp2) / 2;
			l = 0;
            r = 0;

			for (int i = tmp1; i < mid; i++)
				l += arr[i];

			for (int i = mid; i < tmp2; i++)
				r += arr[i];

			if (l == r) {
				cout << finish;
                return 0;
			}
			tmp1++;
            tmp2++;
		}
	}
	cout << '0';
	return 0;
}