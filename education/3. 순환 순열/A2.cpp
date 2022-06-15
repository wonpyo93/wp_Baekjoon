#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int N, P;
void InputData(){
    cin >> N >> P;
}

int main(){
  InputData();// 입력받는 부분

  // 여기서부터 작성
  int c = 1;
  int a = N % P;
  int arr[54321];
  memset(arr, 0, sizeof(arr));

  while(true) {
    arr[a] = c;
    c++;
    a = a * N;
    a = a % P;
    if(arr[a]) {
      cout << c - arr[a];
      break;
    }
  }
  return 0;
}