#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define MAXN ((int)1e3)
int N;
int used[MAXN + 10];
void InputData(){
    cin >> N;
}

bool func(int a) {
  int s = 0;
  while(a > 0) {
    int r = a % 10;
    a = a / 10;
    s += r * r;
  }
  if (s == 1) {
    return true;
  } else if (s > 1 && s <= 4) {
    return false;
  } else {
    return func(s);
  }
}

int main(){
  int ans = -1;
  InputData();//입력받는 부분

  //여기서부터 작성
  for(int i = 1; i <= N; i++) {
    if(func(i)) {
      ans = i;
    }
  }
  cout << ans << endl;//출력하는 부분
  return 0;
}