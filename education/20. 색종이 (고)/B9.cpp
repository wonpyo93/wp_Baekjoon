#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
#include <functional>
#include <map>
#include <iostream>
using namespace std;
int N;//색종이 수
int A[100+10];
int B[100+10];
int C[110][110];
void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
      cin >> A[i] >> B[i];
      for(int j = 1; j <= 10; j++) {
        for(int k = 1; k <= 10; k++) {
          C[A[i] + j][B[i] + k] = 1;
        }
      }
    }
}


int main() {
  int ans = -1;
  memset(C, 0, sizeof(C));
  InputData();//입력받는 부분
  
  //여기서부터 작성  
  for(int i = 1; i <= 100; i++) {
    for(int j = 1; j <= 100; j++) {
      if(C[i][j] == 1) {
        C[i][j] += C[i][j-1];
      }
    }
  }
  int left_end = -1, right_end = -1;
  for(int i = 1; i <= 100; i++) {
    for(int j = 1; j <= 100; j++) {
      if(C[i][j] != 0) {
        left_end = 0;
        while(1) {
          if(C[i][j] <= C[i-left_end][j]) {
            left_end++;
          } else {
            break;
          }
        }
        right_end = 0;
        while(1) {
          if(C[i][j] <= C[i+right_end][j]) {
            right_end++;
          } else {
            break;
          }
        }
        ans = max(ans, (C[i][j] * (left_end + right_end - 1)));
      }
    }
  }
  cout << ans << endl;//출력하는 부분
  return 0;
}