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
int weight = -1;
};
bool cmp(D a, D b) {
  if(a.end == b.end) {
    return a.start < b.start;
  } else {
    return a.end < b.end;
  }
}

int N, C, M;
int S[10000+10];
int E[10000+10];
int NUM[10000+10];
void InputData(){
    cin >> N >> C;
    cin >> M;
    for (int i=0; i<M; i++){
        cin >> S[i] >> E[i] >> NUM[i];
    }
}

int main(){
  int ans = -1;

  InputData();// 입력받는 부분

  // 여기서부터 작성
  vector<D> arr(M);
  
  for(int i = 0; i < M; i++) {
    arr[i].weight = NUM[i];
    arr[i].start = S[i];
    arr[i].end = E[i];
  }
  sort(arr.begin(), arr.end(), cmp);

  int unload[N+1];
  for(int i = 0; i < N+1; i++)
    unload[i] = C;
  ans = 0;
  for(int i = 0; i < M; i++) {
		int tmp = C + 1;
		for(int j = arr[i].start; j < arr[i].end; j++)
      tmp = min(tmp, unload[j]);
    arr[i].weight = min(tmp, arr[i].weight);
    
		for(int j = arr[i].start; j < arr[i].end; j++)
			unload[j] -= arr[i].weight;
    
		ans += arr[i].weight;
    // cout << ans << " " << arr[i].weight << endl;
    // for(int k = 0; k < N+1; k++) {
    //   cout << unload[k] << " ";
    // } cout << endl;
  }

  cout << ans << endl;// 출력하는 부분
  return 0;
}