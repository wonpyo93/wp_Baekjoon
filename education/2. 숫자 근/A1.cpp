#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define MAXN ((int)1e3)
int N;//정수개수
int A[MAXN + 10];//입력 정수
int B[MAXN + 10];//숫자근 값
void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i];
    }
}

int func(int a) {
  //int aaa;
  int toReturn = 0;
  int val = a;
  while(val >= 10) {
    toReturn = 0;
    //cout << "          " << val << endl;
    while(val) {
      toReturn += val % 10;
      val /= 10;
      //cout << toReturn << " " << val << endl;
    }
    val = toReturn;
    //cin >> aaa;
  }
  return toReturn;
}

int main() {
  int ans = 1000001;
  InputData();//입력 받는 부분

  //여기서부터 작성
  memset(B, 0, sizeof(B));
  for(int i = 0; i < N; i++) {
    B[i] = func(A[i]);
    //cout << "i: " << i << ", B = " << B[i] << endl;
  }
  int smallest = -1;
  // for(int i = 0; i < N; i++) {
  //   cout << B[i] << " ";
  // }
  // cout << endl;
  for(int i = 0; i < N; i++) {
    if(B[i] > smallest) {
      ans = A[i];
      smallest = B[i];
    } else if(B[i] == smallest) {
      ans = min(A[i], ans);
    }
  }
  
  cout << ans << endl;//출력하는 부분
  return 0;
}