#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
#include <functional>
#include <map>
using namespace std;
struct Student {
int in = -1;
int out = -1;
};
bool cmp(Student a, Student b) {
  if(a.in == b.in) {
    return a.out < b.out;
  } else {
    return a.in < b.in;
  }
}

int N;
int S[10000+10];
int E[10000+10];
int present;
int absent;
void InputData(void){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> S[i] >> E[i];
    }
}

int main(void){
  InputData();// 입력받는 부분

  // 여기서부터 작성
  vector<Student> arr(N);
  for(int i = 0; i < N; i++) {
    arr[i].in = S[i];
    arr[i].out = E[i];
  }
  sort(arr.begin(), arr.end(), cmp);

  int at_in = 0, at_out = 0;
  present = -1; absent = -1;
  for(int i = 0; i < N; i++) {
    if(arr[i].in <= at_out) {
      at_out = max(at_out, arr[i].out);
      present = max(present, at_out - at_in);
    } else {
      absent = max(absent, arr[i].in - at_out);
      at_in = arr[i].in;
      at_out = arr[i].out;
      present = max(present, at_out - at_in);
    }
  }

  cout << present << " " << absent << endl;// 출력하는 부분
  return 0;
}