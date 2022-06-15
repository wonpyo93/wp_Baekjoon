#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int N;//빌딩의 층수
void InputData(){
    cin >> N;
}
int func(int n){
  int hater = 4;
  if (n < hater)
    return n;
  if (n >= hater && n < 10)
    return n - 1;
  
  int mult = pow(10,int(log10(n)));
  int d = n / mult;
  if (d != hater) return (func(d) * func(mult - 1) + func(d) + func(n % mult));
  else return func((d * mult) - 1);
}
int main(){
  int ans = 0;
  InputData();//입력받는 부분

  //여기서부터 작성
  ans = func(N);
  cout << ans << endl;//출력하는 부분
  return 0;
}