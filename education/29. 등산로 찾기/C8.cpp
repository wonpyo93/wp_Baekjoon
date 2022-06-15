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
#define MAXN (102)
#define INF (12345678)
int N;//산크기
int eh, ew;//목적지 위치 세로, 가로
int map[MAXN][MAXN];
int visited[MAXN][MAXN];
struct POS {
  int x, y;
};
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
POS arr[12345678];

void InputData(){
    cin >> N;
    cin >> eh >> ew;
    for (int h=1; h<=N; h++){
        for (int w=1; w<=N; w++){
            cin >> map[h][w];
            visited[h][w] =  INF;
        }
    }
}


int main(){
  int ans = -1;
  InputData();//입력 받는 부분

  //여기서부터 작성
  int start = 0, end = 0;
  for(int i = 0; i <= N + 1; i++) {
    for(int j = 0; j <= N + 1; j++) {
      if(visited[i][j] == 0) {
        arr[end].y = i;
        arr[end].x = j;
        end++;
      }
    }
  }
  // cout << start << " " << end << endl;
  while(1) {
    if(start == end) {
      break;
    } else {
      for(int i = 0; i < 4; i++) {
        int tmp_x = arr[start].x + dx[i];
        int tmp_y = arr[start].y + dy[i];
        if(tmp_x >= 1 && tmp_y >= 1 && tmp_x <= N && tmp_y <= N) {
          int tmp = map[arr[start].y][arr[start].x] - map[tmp_y][tmp_x];
          if (tmp < 0) {
            tmp = tmp * tmp;
          }
          tmp += visited[arr[start].y][arr[start].x];
          if(visited[tmp_y][tmp_x] > tmp) {
            visited[tmp_y][tmp_x] = tmp;
            arr[end].x = tmp_x;
            arr[end].y = tmp_y;
            end++;
            // cout << tmp_x << " " << tmp_y << "   " << tmp << "   " << start << " " << end << endl;
          }
        }
      }
      start++;
    }
  }
  // for(int i = 0; i < N; i++) {
  //   for(int j = 0; j < N; j++) {
  //     cout << visited[i][j] << "\t";
  //   } cout << endl;
  // }
  cout << visited[eh][ew] << endl;//출력하는 부분
  return 0;
}