#include <iostream>
#include <algorithm> 
#define MAX 1000
using namespace std;

int N, cnt[MAX], arr[MAX], ans;


int main() {
    ans = 0;
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> arr[i];

	for(int i = 0; i < N; i++) {
		cnt[i] = 1;
		for (int j = 0; j < i; j++)
			if (arr[i] > arr[j])
				cnt[i] = max(cnt[i], cnt[j] + 1);
		ans = max(ans, cnt[i]);
	}
	cout << ans;
    return 0;
}