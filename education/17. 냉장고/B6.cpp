#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
#include <functional>
#include <map>
#include <iostream>
using namespace std;
struct D {
int start = -1;
int end = -1;
};
bool cmp(D a, D b) {
  if(a.end == b.end) {
    return a.start < b.start;
  } else {
    return a.end < b.end;
  }
}

int N;
int X[100+10];
int Y[100+10];
void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> X[i] >> Y[i];
    }
}

int main(){
  int ans = -1;

  InputData();// 입력받는 부분

  // 여기서부터 작성
  vector<D> arr(N);
  
  for(int i = 0; i < N; i++) {
    arr[i].start = X[i];
    arr[i].end = Y[i];
  }
  sort(arr.begin(), arr.end(), cmp);

  ans = 0;
  int maxTemp = -11111;
  for(int i = 0; i < N; i++) {
    if(maxTemp < arr[i].start) {
      ans++;
      maxTemp = arr[i].end;
    }
  }

  cout << ans << endl;// 출력하는 부분
  return 0;
}