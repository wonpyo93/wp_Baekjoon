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
#define MAXNM ((int)1e5)
int N, M;//소마리수, 잔디구간 개수
long long A[MAXNM+10];//잔디 구간 시작
long long B[MAXNM+10];//잔디 구간 끝
struct D {
ll start = -1;
ll end = -1;
};
bool cmp(D a, D b) {
  if(a.end == b.end) {
    return a.start < b.start;
  } else {
    return a.end < b.end;
  }
}
void InputData(){
	cin >> N >> M;
	for (int i=0 ; i<M ; i++){
		cin >> A[i] >> B[i];
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long ans = -1;
	InputData();// 입력받는 부분

	// 여기서부터 작성
  vector<D> arr(M);
  for(int i = 0; i < M; i++) {
    arr[i].start = A[i];
    arr[i].end = B[i];
  }
  sort(arr.begin(), arr.end(), cmp);

  ll start = 0;
  ll end = ((arr[M-1].end + 1));
  ll mid = (start + end) / 2;
  ll tmp_at;
  bool flag = false;
  
  while(start <= end) {
    mid = (start + end) / 2;
    // cout << start << " " << mid << " " << end << endl;
    ll tmp_idx = 0, cnt = 0, rem = N - 1;
    tmp_at = arr[0].start;
    flag = false;
    for(int i = 1; i < N; i++) {
      tmp_at += mid;
      while(1) {
        if(tmp_at > arr[tmp_idx].end && tmp_idx < M) {
            tmp_idx++;
        } else {
          if(tmp_idx >= M) {
            flag = true;
            break;
          }
          // cout << tmp_at << "-->";
          if(tmp_at < arr[tmp_idx].start) {
            tmp_at = arr[tmp_idx].start;
            break;
          } else break;
        }
      }
      // cout << tmp_at << " " << tmp_idx << endl;
      if(flag) break;
      if(tmp_at > arr[M - 1].end) {
        // cout << "fail" << endl;
        flag = true;
        break;
      }
    }
    if(!flag) {
      ans = mid;
      start = mid + 1;
      // cout << "    " << "right" << endl;
    } else {
      end = mid - 1;
      // cout << "    " << "left" << endl;
    } 
  }
  cout << ans << endl;//출력하는 부분
  return 0;
}