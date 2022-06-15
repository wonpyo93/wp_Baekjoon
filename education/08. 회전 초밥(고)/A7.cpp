#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int N, D, K, C;
int A[3000000+10];
void InputData(){
    cin >> N >> D >> K >> C;
    for (int i=0; i<N ; i++){
        cin >> A[i];
    }
}

int main(){
  int ans = 1;

  InputData();// 입력받는 부분

  // 여기서부터 작성
  int arr[D+10];
  memset(arr, 0, sizeof(arr));
  arr[C] = 1;
  for(int j = 0; j < K; j++) {
    arr[A[(j) % N]]++;
    if(arr[A[(j) % N]] == 1) ans++;
  }
  int cnt = ans;
  for(int i = 1; i < N; i++) {
    arr[A[(N - 1 + i) % N]]--;
    if (arr[A[(N - 1 + i) % N]] == 0) cnt--;
    arr[A[(i + K - 1) % N]]++;
    if (arr[A[(i + K - 1) % N]] == 1) cnt++;
    ans = max(ans, cnt);
  }

  cout << ans << endl;// 출력하는 부분
  return 0;
}