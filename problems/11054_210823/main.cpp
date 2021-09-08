#include <iostream>
#include <algorithm> 
#define MAX 1000
using namespace std;

int N, cnt_up[MAX], cnt_down[MAX], arr[MAX], ans;


int main() {
    ans = 0;
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> arr[i];

	for(int i = 0; i < N; i++) {
		cnt_up[i] = 1;
		for(int j = 0; j < i; j++)
			if(arr[i] > arr[j])
				cnt_up[i] = max(cnt_up[i], cnt_up[j] + 1);
		// ans = max(ans, cnt_up[i]);
	}
    for(int i = N - 1; i >= 0; i--) {
        cnt_down[i] = 1;
        for(int j = N - 1; j > i; j--)
            if(arr[i] > arr[j])
                cnt_down[i] = max(cnt_down[i], cnt_down[j] + 1);
    }
    for(int i = 0; i < N; i++)
        ans = max(ans, (cnt_up[i] + cnt_down[i] - 1));
	cout << ans;
    return 0;

    // for(int i = 0; i < N; i++)
    //     cout << cnt_up[i] << " ";
    // cout << endl;
    // for(int i = 0; i < N; i++)
    //     cout << cnt_down[i] << " ";
    // cout << endl;
}