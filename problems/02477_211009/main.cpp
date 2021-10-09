#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int N, area, ans, tmp;
vector<pair<int, int>> arr(6);
int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N;
	for(int i = 0; i < 6; i++)
		cin >> arr[i].first >> arr[i].second;
	
	area = ans = -1;

	for(int i = 0; i < 6; i++) {
		tmp = arr[i].second * arr[(i + 1) % 6].second;
		if(area == -1 || tmp > area) {
			area = tmp;
			ans = area - arr[(i + 3) % 6].second
                    * arr[(i + 4) % 6].second;
		}
	}

	cout << ans * N << endl;
	return 0;
}