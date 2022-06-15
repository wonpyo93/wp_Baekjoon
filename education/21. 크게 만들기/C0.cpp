#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
//#include <functional>
//#include <map>
#include <iostream>
using namespace std;
#define MAXN ((int)5e5)
int N, K;
char str[MAXN + 10];

void InputData() {
	cin >> N >> K;
	cin >> str;
}

int main() {
	InputData();//입력 받는 부분

	//여기서부터 작성
  vector<char> vec;
  for(int i = 0; i < N; i++) {
    while(K != 0) {
      if(!vec.empty() && vec.back() < str[i]) {
        vec.pop_back();
        K--;
      } else break;
      //cout << i << " " << K << " " << vec.front() << endl;
    }
    vec.push_back(str[i]);
  }
  while(K > 0) {
    vec.pop_back();
    K--;
  }
  for(int i = 0; i < vec.size(); i++) {
    cout << vec[i];
  }

	return 0;
}