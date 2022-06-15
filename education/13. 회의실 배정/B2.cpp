#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
#include <functional>
#include <map>
using namespace std;

int N;
int ID[500+10];
int S[500+10];
int E[500+10];
int sol[500+10];
struct D {
int start = -1;
int end = -1;
int idx = -1;
};
bool cmp(D a, D b) {
  if(a.end == b.end) {
    return a.start < b.start;
  } else {
    return a.end < b.end;
  }
}
void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> ID[i] >> S[i] >> E[i];
    }
}
void OutputData(int ans){
    cout << ans << endl;
    for (int i=0; i < ans; i++){
        cout << sol[i] << " ";
    }
    cout << endl;
}

int main(){
  int ans = -1;

  InputData();// 입력받는 부분

  //여기서부터 작성
  vector<D> arr(N);
  
  for(int i = 0; i < N; i++) {
    arr[i].idx = ID[i];
    arr[i].start = S[i];
    arr[i].end = E[i];
  }
  sort(arr.begin(), arr.end(), cmp);

  int idx_end = -1;
  ans = 0;
  for(int i = 0; i < N; i++) {
    if(idx_end <= arr[i].start) {
      idx_end = arr[i].end;
      sol[ans] = arr[i].idx;
      ans++;
    }
  }
  
  OutputData(ans);// 출력하는 부분
  return 0;
}