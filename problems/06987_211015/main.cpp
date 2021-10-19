//문제를 너무 단순히 보고 풀었지만 틀렸다.
//왜 틀린지 이유를 찾을 수는 없었지만 탐색으로 푸는게 더 나을 것 같다고 판단하여,
//다시 문제를 풀었다.

#include <iostream>
#include <string.h>
#include <algorithm>
#define endl '\n'
using namespace std;
 
int arr[6][3], orig[4][6][3], res[4];

pair<int, int> game[15] = { {0,1},{0,2},{0,3},{0,4},{0,5},{1,2},{1,3},{1,4},{1,5},{2,3},{2,4},{2,5},{3,4},{3,5},{4,5} };
 
void dfs(int cnt) {	
	if(cnt == 15) {
		for(int k = 0; k < 4; k++) {
			bool flag = true;
			for(int i = 0; i < 6; i++) {
				for(int j = 0; j < 3; j++) {
					if(arr[i][j] != orig[k][i][j]) {
						flag = false;
						break;
					}
				}
				if(!flag)
					break;
			}
			if(flag)
				res[k] = 1;
		}
		return;
	}
	int i = game[cnt].first;
	int j = game[cnt].second;

	arr[i][0]++;
	arr[j][2]++;
	dfs(cnt + 1);
	arr[i][0]--;
	arr[j][2]--;

	arr[i][1]++;
	arr[j][1]++;
	dfs(cnt + 1);
	arr[i][1]--;
	arr[j][1]--;

	arr[i][2]++;
	arr[j][0]++;
	dfs(cnt + 1);
	arr[i][2]--;
	arr[j][0]--;	
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(arr, 0, sizeof(arr));
	memset(res, 0, sizeof(res));

	for(int k = 0; k < 4; k++)
		for(int i = 0; i < 6; i++)
			for(int j = 0; j < 3; j++)
				cin >> orig[k][i][j];

	dfs(0);

	for(int i = 0; i < 4; i++)
		cout << res[i] << " ";
		
	return 0;
}