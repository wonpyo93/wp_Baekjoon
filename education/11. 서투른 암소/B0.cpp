#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
#include <functional>
#include <map>
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
  for (int i = 0; i < N; i++) {
    if (str[i] == '(')
      offBy++;
		else offBy--;
 
		if (offBy < 0) {
			ans++;
			offBy = 1;
		}
	}
	if(offBy > 0)
    ans += offBy / 2;
  
  cout << ans << endl;// 출력하는 부분
  return 0;
}