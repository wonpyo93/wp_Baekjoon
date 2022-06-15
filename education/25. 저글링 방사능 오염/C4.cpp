#define ll long long
#include <algorithm>
#include <cstring>
#include <math.h>
#include <queue>
#include <vector>
//#include <functional>
//#include <map>
#include <iostream>
using namespace std;
#define MAXN (100)
int W, H;//지도의 가로 세로 크기
char map[MAXN+10][MAXN+10];//지도 정보('1':저글링, '0':빈곳)
int visited[MAXN+10][MAXN+10];
int sw, sh;//시작위치 가로 세로 좌표
int total_cnt;
void InputData(){
    cin >> W >> H;
    for (int i=1; i<=H; i++){
      cin >> &map[i][1];
      for(int j = 1; j <= W; j++) {
        if(map[i][j] == '1') {
          total_cnt++;
        }
      }
      
    }
    cin >> sw >> sh;
}

int main(){
  total_cnt = 0;
  int ans = 0;
  InputData();//입력 받는 부분

  //여기서부터 작성
  // cout << total_cnt << endl;
  memset(visited, 0, sizeof(visited));

  int cnt = 0;
  queue<pair<int,int>> q;
  q.push(pair<int,int>(sh,sw));
  visited[sh][sw] = 1;
  while(!q.empty()) {
    pair<int,int> a = q.front();
    ans = max(ans, visited[a.first][a.second]);
    cnt++;
    // cout << "ans is " << ans << ", cnt is " << cnt << endl;
    q.pop();
    // cout << a.first << " " << a.second << endl;
    if(map[a.first + 1][a.second] == '1' && visited[a.first + 1][a.second] == 0) {
      visited[a.first+1][a.second] = visited[a.first][a.second] + 1;
      q.push(pair<int,int>(a.first+1,a.second));
    }
    if(map[a.first - 1][a.second] == '1' && visited[a.first - 1][a.second] == 0) {
      visited[a.first-1][a.second] = visited[a.first][a.second] + 1;
      q.push(pair<int,int>(a.first-1,a.second));
    }
    if(map[a.first][a.second + 1] == '1' && visited[a.first][a.second + 1] == 0) {
      visited[a.first][a.second+1] = visited[a.first][a.second] + 1;
      q.push(pair<int,int>(a.first,a.second+1));
    }
    if(map[a.first][a.second - 1] == '1' && visited[a.first][a.second - 1] == 0) {
      visited[a.first][a.second-1] = visited[a.first][a.second] + 1;
      q.push(pair<int,int>(a.first,a.second-1));
    }
  }
  // for(int i = 1; i <= H; i++) {
  //   for(int j = 1; j <= W; j++) {
  //     cout << visited[i][j];
  //   }
  //   cout << endl;
  // }
  // cout << endl;
  // cout << "ans is " << ans << ", cnt is " << cnt << endl;
  cout << ans + 2 << endl << total_cnt - cnt;
  return 0;
}