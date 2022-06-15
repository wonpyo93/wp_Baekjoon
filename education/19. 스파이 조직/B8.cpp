#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
#include <functional>
#include <map>
#include <iostream>
using namespace std;

int N;
string A;
void InputData(){
    cin >> N >> A;
}

int main (){
  InputData();// 입력받는 부분

  // 여기서부터 작성
  int ans[12345];
  int ans_cnt = 0;
  int len = A.length();
  int depth = 0;
  for(int i = 0; i < len; i++) {
    if(A[i] == '<') {
      depth++;
    } else if(A[i] == '>') {
      depth--;
    } else {
      int to;
      for(int j = 0; j < 7; j++) {
        if(A[i + j] != '<' && A[i + j] != '>') {
          to = j;
        } else {
          break;
        }
      }
      if(depth == N) {
        ans[ans_cnt] = stoi(A.substr(i, to+1));
        ans_cnt++;
      }
      i+=to;
    }
  }
  for(int i = 0; i < ans_cnt; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}