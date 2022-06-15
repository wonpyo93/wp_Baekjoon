#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
#include <functional>
#include <map>
using namespace std;

int K;
int A[6+10];
int B[6+10];
int max_x = 0, max_y = 0;
int at_x, at_y;
void InputData(){
  cin >> K;
  for (int i=0 ; i<6 ; i++){
    cin >> B[i] >> A[i];
    if(B[i] == 1 || B[i] == 2) {
      if(A[i] > max_x) {
        max_x = A[i];
        at_x = i;
      }
    } else {
      if(A[i] > max_y) {
        max_y = A[i];
        at_y = i;
      }
    }
  }
}

int main(){
  int ans = -1;
  InputData();// 입력받는 부분

  // 여기서부터 작성
  int area_total = max_x * max_y;
  int area_small = -1;
  int min_x = 0, min_y = 0;
  //cout << at_x << " " << max_x << "      " << at_y << " " << max_y << endl;
  if(at_x > at_y || (at_x == 0 && at_y == 5)) {
    area_small = (max_y - (A[(at_x+1)%6])) * (max_x - A[(6+at_y-1)%6]);
  } else {
    area_small = (max_y - (A[(6+at_x-1)%6])) * (max_x - A[(at_y+1)%6]);
  }
  int area = area_total - area_small;
  //cout << area_total << " " << area_small << endl;
  ans = area * K;
  cout << ans << endl;// 출력하는 부분
  return 0;
}