#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int N;
double D[10000+10];
void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> D[i];
    }
}

int main(){
  double ans = -1;

  InputData();// 입력받는 부분

  // 여기서부터 작성
  ans = D[0];
  for(int i = 0; i < N; i++) {
    double from = D[i];
    //cout << " " << from << endl;
    for(int j = i + 1; j < N; j++) {
      if(from > ans) ans = from;
      //cout << "  " << ans;
      from *= D[j];
    }
    if (from > ans) ans = from;
    //cout << "  " << ans << endl;
  }

  printf("%.3lf\n", ans);// 출력하는 부분
  return 0;
}