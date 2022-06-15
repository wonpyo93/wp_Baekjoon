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
int A[100+10];
int B[100+10];
int C[110][110];  
void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
      cin >> A[i] >> B[i];
      for(int j = 0; j < 10; j++) {
        for(int k = 0; k < 10; k++) {
          C[A[i] + j][B[i] + k] = 1;
        }
      }
    }
}

int main(){
  int ans = 0;

  InputData();// 입력받는 부분

  // 여기서부터 작성
  for(int i = 0; i < 100; i++) {
    for(int j = 0; j < 100; j++) {
      if(C[i][j] == 1) {
        if(C[i-1][j] == 0) ans++;
        if(C[i+1][j] == 0) ans++;
        if(C[i][j-1] == 0) ans++;
        if(C[i][j+1] == 0) ans++;
      }
    }
  }

  cout << ans << endl;// 출력하는 부분
    return 0;
}