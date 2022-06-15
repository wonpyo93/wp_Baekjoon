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
#define MAXN (50)
int R, C;//지도 세로, 가로 크기
int map[MAXN+10][MAXN+10];
int visited[MAXN+10][MAXN+10];
int dest_x, dest_y;
struct POS {
  int x, y;
};
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
void func() {
  queue<POS> q = queue<POS>();
  for(int i = 1; i < R + 1; i++) {
    for(int j = 1; j < C + 1; j++) {
      if(map[i][j] == -1) {
        visited[i][j] = -1;
        POS tmp; tmp.x = i; tmp.y = j;
        q.push(tmp);
      }
    }
  }
  for(int i = 1; i < R + 1; i++) {
    for(int j = 1; j < C + 1; j++) {
      if(map[i][j] == 1) {
        visited[i][j] = 1;
        POS tmp; tmp.x = i; tmp.y = j;
        q.push(tmp);
      }
    }
  }
  // cout << q.size() << endl;
  while(!q.empty()) {
    POS tmp = q.front();
    q.pop();
    // cout << tmp.x << " " << tmp.y << endl;
    if(map[tmp.x][tmp.y] == 1) {
      for(int i = 0; i < 4; i++) {
        if(map[tmp.x + dx[i]][tmp.y + dy[i]] == 0 || map[tmp.x + dx[i]][tmp.y + dy[i]] == 2) {
          if(visited[tmp.x + dx[i]][tmp.y + dy[i]] == 0) {
            POS nxt; nxt.x = tmp.x + dx[i]; nxt.y = tmp.y + dy[i];
            q.push(nxt);
            map[nxt.x][nxt.y] = 1;
            visited[nxt.x][nxt.y] = visited[tmp.x][tmp.y] + 1;
          }
        }
      }
    } else if(map[tmp.x][tmp.y] == -1) {
      visited[tmp.x][tmp.y] = -1;
      for(int i = 0; i < 4; i++) {
        if(map[tmp.x + dx[i]][tmp.y + dy[i]] == 0) {
          if(visited[tmp.x + dx[i]][tmp.y + dy[i]] == 0) {
            POS nxt; nxt.x = tmp.x + dx[i]; nxt.y = tmp.y + dy[i];
            q.push(nxt);
            map[tmp.x + dx[i]][tmp.y + dy[i]] = -1;
            visited[tmp.x + dx[i]][tmp.y + dy[i]] = -1;
          }
        }
      }
    }
  }
}
void InputData(){
  string str;
  cin >> R >> C;
  for(int i = 0; i < R + 2; i++) {
    for(int j = 0; j < C + 2; j++) {
      visited[i][j] = -2;
      map[i][j] = -2;
    }
  }
  
  for(int i = 1; i < R + 1; i++) {
    cin >> str;
    for(int j = 1; j < C + 1; j++) {
      if(str[j-1] == '*') {
        map[i][j] = -1;
        visited[i][j] = -1;
      } else if(str[j-1] == 'S') {
        map[i][j] = 1;
        visited[i][j] = 0;
      } else if(str[j-1] == 'X') {
        map[i][j] = -2;
        visited[i][j] = -1;
      } else if(str[j-1] == 'D') {
        map[i][j] = 2;
        visited[i][j] = 0;
        dest_x = i; dest_y = j;
      } else {
        map[i][j] = 0;
        visited[i][j] = 0;
      }
    }
  }

  // cout << endl;
  // for(int i = 1; i < R + 1; i++) {
  //   for(int j = 1; j < C + 1; j++) {
  //     cout << visited[i][j] << "\t";
  //   } cout << endl;
  // }
  // cout << endl;
  // for(int i = 1; i < R + 1; i++) {
  //   for(int j = 1; j < C + 1; j++) {
  //     cout << map[i][j] << "\t";
  //   } cout << endl;
  // }
}
int main(){
  int T, ans = -1;
  scanf("%d", &T);
  for (int t=1; t<=T; t++){
    InputData();//입력 받는 부분
    // 여기서부터 작성
    func();
    
    // for(int i = 1; i < R + 1; i++) {
    //   for(int j = 1; j < C + 1; j++) {
    //     cout << visited[i][j] << "\t";
    //   } cout << endl;
    // }
    
    bool flag = false;
    for(int i = 1; i < R + 1; i++) {
      for(int j = 1; j < C + 1; j++) {
        if(map[i][j] == 2) {
          flag = true;
        }
        ans = max(ans, visited[i][j]);
      }
    }
    if(flag) {
      cout << "KAKTUS" << endl;
    } else {
      cout << visited[dest_x][dest_y] - 1 << endl;
    }
  }
  return 0;
}