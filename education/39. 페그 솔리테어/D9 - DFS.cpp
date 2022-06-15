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
#define MAXH (5)
#define MAXW (9)
char map[MAXH+2][MAXW+2];
int zmap[MAXH+2][MAXW+2];
int solremain, solmove;
int numPin;
bool flag;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
void InputData(){
  for (int h=1; h<=MAXH; h++){
    cin >> &map[h][1];
  }
}
void showMap() {
  cout << endl;
  for(int i = 1; i <= MAXH; i++) {
    for(int j = 1 ; j <= MAXW; j++) {
      cout << zmap[i][j];
    } cout << endl;
  }
}
void dfs(int idx, int cnt) {
  if(!flag) {
    solremain = min(solremain, cnt);
    solmove = max(solmove, idx);
    // showMap();
    if(cnt == 1) {
      flag = true;
      return;
    }
    for(int i = 1; i < MAXH+2; i++) {
      for(int j = 1; j < MAXW+2; j++) {
        if(zmap[i][j] == 1) {
          for(int k = 0; k < 4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if(nx+dx[k] > 0 && nx+dx[k] < MAXH+2 && ny+dy[k] > 0 && ny+dy[k] < MAXW+2 && zmap[nx][ny] == 1 && zmap[nx+dx[k]][ny+dy[k]] == 0) {
              //can jump
              zmap[i][j] = 0; zmap[nx][ny] = 0; zmap[nx+dx[k]][ny+dy[k]] = 1;
              dfs(idx + 1, cnt-1);
              zmap[i][j] = 1; zmap[nx][ny] = 1; zmap[nx+dx[k]][ny+dy[k]] = 0;
            }
          }
        }
      }
    }
  }
}
int main(){
  int T;
  cin >> T;
  for (int t=1; t<=T; t++){
    numPin = 0; solremain = INF; solmove = 0; flag = false;
    memset(map, 0, sizeof(map));
    InputData();//입력받는 부분
    //여기서부터 작성
    for(int i = 1; i <= MAXH; i++) {
      for(int j = 1; j <= MAXW; j++) {
        if(map[i][j] == '#') {
          zmap[i][j] = 2;
        } else if(map[i][j] == '.') {
          zmap[i][j] = 0;
        } else if(map[i][j] == 'o') {
          zmap[i][j] = 1;
          numPin++;
        }
      }
    }
    dfs(0, numPin);
    cout << solremain << " " << solmove << endl;//출력하는 부분
  }
  return 0;
}