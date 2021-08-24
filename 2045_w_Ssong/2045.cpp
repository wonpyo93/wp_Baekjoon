#include <iostream>
#include <algorithm>
using namespace std;
int arr[3][3], sum, total = 0;

int main() {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
            cin >> arr[i][j];
			total += arr[i][j];
		}
	}
    
	if(arr[0][0] + arr[1][1] + arr[2][2] == 0 || arr[0][2] + arr[1][1] + arr[2][0] == 0)
		sum = total / 2;
	else {
		sum = arr[1][1] + max(arr[0][0] + arr[2][2], arr[0][2] + arr[2][0]);
		for(int i = 0; i < 3; i++) {
			int temp_1 = 0, temp_2 = 0;
			for (int j = 0; j < 3; j++) {
                temp_1 += arr[i][j];
                temp_2 += arr[j][i];
            }
			sum = max({sum, temp_1, temp_2});
		}
	}

    for(int i = 0; i < 3; i++) {
        int cnt = 0, s = 0, idx = -1;
        for(int j = 0; j < 3; j++) {
            int val = arr[i][j];
            if(val == 0) {
                idx = j;
                cnt++;
            }
            s += val;
        }
        if(cnt == 1) {
            if(sum - s != 0)
                arr[i][idx] = sum - s;
        }
	}


    for(int i = 0; i < 3; i++) {
        int cnt = 0, s = 0, idx = -1;
        for(int j = 0; j < 3; j++) {
            int val = arr[j][i];
            if (val == 0) {
                idx = j;
                cnt++;
            }
            s += val;
        }
        if (cnt == 1) {
            if(sum - s != 0)
                arr[idx][i] = sum - s;
        }
	}

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++)
            cout << arr[i][j] << " ";
        cout << endl;
	}
}