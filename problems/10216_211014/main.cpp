#include <iostream>
#include <string.h>
#define endl '\n'
using namespace std;

struct info{
	int x, y, r;  
};

info arr[3333];
int visited[3333];
int N, T;

void dfs(int i) {
	if(visited[i])
        return; 
	visited[i] = 1;

	for(int j = 0; j < N; j++) {
		if(i == j)
            continue;

		if((arr[i].x - arr[j].x) * (arr[i].x - arr[j].x) + (arr[i].y - arr[j].y) * (arr[i].y - arr[j].y) <= (arr[i].r + arr[j].r) * (arr[i].r + arr[j].r))
			dfs(j);
	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
	while (T--) {
        memset(visited, 0, sizeof(visited));

        cin >> N;
        
		for(int i = 0; i < N; i++)
            cin >> arr[i].x >> arr[i].y >> arr[i].r;

		int cnt = 0;

		for(int i = 0; i < N; i++) {
			if(!visited[i]) {
				dfs(i);
				cnt++;
			}
		}
        cout << cnt << endl;
	}
	return 0;  
}