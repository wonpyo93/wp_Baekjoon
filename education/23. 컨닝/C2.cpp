#define ll long long
#include <algorithm>
#include <cstring>
#include <math.h>
#include <queue>
#include <vector>
//#include <functional>
//#include <map>
#include <iostream>
using namespace std;
#define MAXN ((int)1e5)
int N; //개수
int F[MAXN + 10];

void InputData() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> F[i];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long ans = -1;

	InputData(); // 입력받는 부분

	// 여기서부터 작성
  vector<ll> vec;
  for(int i = 0; i < N; i++) {
    vec.push_back(F[i]);
  }
  sort(vec.begin(), vec.end());
  
  ans = 0;
  ll cnt = 0;
  double tmp;

  for(int i = 0; i < N; i++) {
    tmp = (double)(vec[i]) * 0.9;
    while(1) {
      if(vec[cnt] >= tmp) {
        break;
      } else {
        cnt++;
      }
    }
    ans += (i - cnt);
  }

	cout << ans << "\n"; // 출력하는 부분
	return 0;
}