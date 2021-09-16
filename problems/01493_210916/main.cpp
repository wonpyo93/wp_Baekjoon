#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int L, W, H, N, A, B, cnt = 0;
bool flag;

int arr[20];

vector <pair<int, int>> v; //2의 a승과 그 개수를 저장

void func(int l, int w, int h, int idx) {
	if(l == 0 || w == 0 || h == 0)
        return;
	for(int i = idx; i < v.size(); i++) {
		if (v[i].second != 0 && l >= v[i].first && w >= v[i].first && h >= v[i].first) {
			v[i].second--;
			cnt++;
			func(l - v[i].first, w, h, i);
			func(v[i].first, w - v[i].first, h, i);
			func(v[i].first, v[i].first, h - v[i].first, i);
			return;
		}
	}
	flag = true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    flag = false;

	cin >> L >> W >> H;
    cin >> N;

	for(int n = 0; n < N; n++) {
		cin >> A >> B;
		arr[A] += B;
	}

	for(int i = 19; i >= 0; i--) {
		if (arr[i] != 0) {
			v.push_back(make_pair(pow(2, i), arr[i]));
		}
	
    }
	func(L, W, H, 0);

	if(flag == true)
        cout << -1;
	else
        cout << cnt;;
	return 0;
}