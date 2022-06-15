#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define MAXN (100)
int K;//처음 폭탄을 가진 사람 번호
int N;//퀴즈 개수
int T[MAXN+10];//걸린 시간
char Z[MAXN+10];//정답 여부
void InputData(){
    cin >> K;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> T[i] >> Z[i];
    }
}

int main(){
  int ans = -1;
  InputData();//입력받는 부분

  //여기서부터 작성
  int time = 0;
  bool flag = false;
  for(int i = 0; i < N; i++) {
    //cout << "K : " << K << ", time : " << time << endl;
    if(flag == true) {
      K++;
      flag = false;
    }
    if (time + T[i] > 211) {
      break;
    } else {
      if(Z[i] == 'F') {
        time = time + T[i];
      } else if(Z[i] == 'T') {
        time = time + T[i];
        flag = true;
      } else {
        //P
      }
    }
  }
  ans = K % 8;
  if (ans == 0) ans = 8;
    cout << ans << endl;//출력하는 부분
    return 0;
}