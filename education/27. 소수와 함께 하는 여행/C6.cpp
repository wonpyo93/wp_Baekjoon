#define ll long long
//#include <functional>
//#include <map>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int S, E;//출발 정류장 번호, 도착 정류장 번호
int visited[99999];

bool checkPrime(int n) {
  if (n == 0 || n == 1) {
    return false;
  }
  for (int i = 2; i <= n / 2; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
void InputData(){
    cin >> S >> E;
}
int main(){
  int ans = -1;
  InputData();// 입력받는 부분

  // 여기서부터 작성
  memset(visited, 0, sizeof(visited));
  queue<int> q;
	q.push(S);
	visited[S] = 1;
  int d[4];
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == E) {
      break;
    }
		for(int i = 0; i < 4; i++) {
      d[0] = x / 1000, d[1] = (x % 1000) / 100, d[2] = (x % 100) / 10, d[3] = x % 10;
			for(int j = 0; j <= 9; j++) {
				if (d[i] == j) {
          continue;
        } else {
  				d[i] = j;
  				int tmp = d[0] * 1000 + d[1] * 100 + d[2] * 10 + d[3];
  				if(checkPrime(tmp) && visited[tmp] == 0 && tmp >= 1000) {
  					visited[tmp] = visited[x] + 1;
  					q.push(tmp);
            // cout << tmp << endl;
  				} 
        }
			}
		}
	}

  cout << visited[E] - 1 << endl;// 출력하는 부분
  return 0;
}