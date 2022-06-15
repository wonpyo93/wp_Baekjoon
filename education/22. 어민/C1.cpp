#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
//#include <functional>
//#include <map>
#include <iostream>
#include <stdio.h>
using namespace std;
int N;//마을 수
long long A[100000+10];//마을 위치
long long B[100000+10];//잡힌 물고기 양
long long idx_max = -1;
long long idx_min = -1;
void InputData(){
  scanf("%d", &N);
  for (int i=0; i<N; i++){
    scanf("%lld %lld", &A[i], &B[i]);
    if(B[idx_max] < B[i]) {
      idx_max = i;
    }
    if(B[idx_min] > B[i]) {
      idx_min = i;
    }
  }
}
int main(){
  long long ans = 0;
  InputData();//입력받는 부분

  //여기서부터 작성
  long long start = 0;
  long long end = B[idx_max];
  long long mid = (start + end) / 2;
  long long tmp;
  while(start <= end) {
    mid = (start + end) / 2;
    // cout << start << " " << mid << " " << end << endl;
    long long rem = 0;
    for(int i = 0; i < N - 1; i++) {
      tmp = B[i] - mid;
      rem += tmp;
      // cout << " " << rem << " --> ";
      if(rem >= 0 && (rem - A[i + 1] + A[i]) < 0) {
        rem = 0;
      } else {
        rem -= A[i + 1] - A[i];
      }
      // cout << rem << "  " << tmp << endl;
    }
    rem += (B[N - 1] - mid);
    // cout << "  " << rem << endl;
    if(rem >= 0) {
      ans = mid;
      start = mid + 1;
      // cout << "    " << "right" << endl;
    } else {
      end = mid - 1;
      // cout << "    " << "left" << endl;
    } 
  }
  if(ans == 0) {
    ans = B[idx_min];
  }
  cout << ans << endl;//출력하는 부분
  return 0;
}