#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
#include <functional>
#include <map>
using namespace std;
using namespace std;
#define MAXN ((int)1e5)
int N;//영화수
struct DATA{
    int s = -1, e = -1;
};
DATA A[MAXN + 10];
bool cmp(DATA a, DATA b) {
  if(a.s == b.s) {
    return a.e < b.e;
  } else {
    return a.s < b.s;
  }
}
void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i].s >> A[i].e;
    }
}

int main(){
	int ans = -1;
	InputData();//입력받는 부분

	//여기서부터 작성
  vector<DATA> arr(N);
  for(int i = 0; i < N; i++) {
    arr[i].s = A[i].s;
    arr[i].e = A[i].e;
  }
  sort(arr.begin(), arr.end(), cmp);
  int idx_end = -1;
  ans = 0;
  for(int i = 0; i < N; i++) {
    if(idx_end <= arr[i].s) {
      if((arr[i].e - arr[i].s >= 2)) {
        idx_end = arr[i].e;
        ans++;
      }
    } else {
      if(idx_end > arr[i].e && (arr[i].e - arr[i].s >= 2)) {
        idx_end = arr[i].e;
      }
    }
  }
  
	cout << ans << "\n";//출력하는 부분
	return 0;
}