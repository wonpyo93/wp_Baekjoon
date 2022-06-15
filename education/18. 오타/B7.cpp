#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
#include <functional>
#include <map>
#include <iostream>
using namespace std;

string str;
void InputData(){
    cin >> str;
}

int main(){
  int ans = 0;

  InputData();// 입력받는 부분

  // 여기서부터 작성
  int N = str.length();
  int offBy = 0;
  int leftCnt = 0, rightCnt = 0;
  bool flag = false;
  if(str[N-1] == '(') {
    ans = 1;
  } else {
    for (int i = 0; i < N; i++) {
      if (str[i] == '(') {
        offBy++;
        if(offBy >= 2) {
          leftCnt++;
        }
      } else {
        offBy--;
        rightCnt++;
        if(offBy == -1) {
          flag = true;
          ans = rightCnt;
          break;
        }
        if(offBy < 2) {
          leftCnt = 0;
        }
      }
  	}
    if(!flag) {
      ans = leftCnt;
    }
  }

  cout << ans << endl;// 출력하는 부분
  return 0;
}