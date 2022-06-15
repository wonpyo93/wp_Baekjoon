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
#define INF 123456789

int N;
int W[20];
int visited[20];
int ans;
void InputData(){
    cin >> N;
    for (int i=0 ; i<N ; i++){
        cin >> W[i];
    }
}
void bfs(int idx, int cnt, int sum) {
  ans = max(ans, cnt);
  // cout << "bfs__" << idx << "\t" << cnt << "\t" << sum << endl;
  if(idx == N - 1) return;
  if(ans > cnt + (N - idx - 1)) return;
  for(int i = idx; i < N; i++) {
    if(visited[i] == 1) continue;
    bool checkFlag = false;
    if(cnt > 0) {
      int lenA = to_string(sum).length(), lenB = to_string(W[i]).length();
      // cout << "comparing " << sum << " and " << W[i] << ":  " << lenA << "," << lenB << "-->" << min(lenA, lenB) << endl;
      for(int j = 0; j < min(lenA, lenB); j++) {
        int tmpA = stoi(to_string(sum).substr(lenA - j - 1,1));
        int tmpB = stoi(to_string(W[i]).substr(lenB - j - 1,1));
        // cout << "   " << j << ": " << tmpA << " " << tmpB << endl;
        if(tmpA + tmpB > 9) { checkFlag = true; break;}
      }
    }
    if(!checkFlag) {
      visited[i] = 1;
      bfs(i, cnt + 1, sum + W[i]);
      visited[i] = 0;
    }
  }
}

int main(){
  ans = -1;
  InputData();// 입력받는 부분
  // 여기서부터 작성
  memset(visited,0,sizeof(visited));
  bfs(0, 0, 0);
  
  cout << ans << endl;//출력하는 부분
  return 0;
}