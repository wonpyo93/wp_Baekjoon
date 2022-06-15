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
#define MAXN (15)
int R, C;//게임판 행(세로), 열(가로) 크기
char map[MAXN+5][MAXN+5];//게임판('#':벽, '.':빈공간, 'R':빨간구슬, 'B':파란구슬, 'H':목표구멍)
int N, M;
int visited[10][10][10][10];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
struct CURR_POS{
  int x, y;
};
CURR_POS init_red, init_blue;
queue<CURR_POS> q_red;
queue<CURR_POS> q_blue;
queue<int> q_cnt;
void InputData(){
	cin >> R >> C;
  for(int y = 0; y < R; y++) {
      for(int x = 0; x < C; x++) {
          cin >> map[y][x];
          if(map[y][x] == 'R'){
              init_red.x = x;
              init_red.y = y;
              map[y][x] = '.';
          }
          else if(map[y][x] == 'B'){
              init_blue.x = x;
              init_blue.y = y;
              map[y][x] = '.';
          }
      }
  }
}

int func(){
    while(!q_red.empty()){
      CURR_POS at_red = q_red.front();
      CURR_POS at_blue = q_blue.front();
      int at_cnt = q_cnt.front();

      q_red.pop(); q_blue.pop(); q_cnt.pop();
      
      if(at_cnt >= 10) {
        // cout << "cnt overflow" << endl;
        break;
      }
      for(int i = 0; i < 4; i++) {
        int rx = at_red.x  + dx[i], ry = at_red.y  + dy[i];
        int bx = at_blue.x + dx[i], by = at_blue.y + dy[i];
        int cnt = at_cnt + 1;
        //cout << ry << " " << rx << "     " << by << " " << bx << " " << cnt << endl;

        if(map[ry][rx] == '#') {
          rx = at_red.x; ry = at_red.y;
        }
        if(map[by][bx] == '#') {
          bx = at_blue.x; by = at_blue.y;
        }
  			if(rx == bx && ry == by) {
          continue;
        } else if(visited[ry][rx][by][bx] == 1) {
          continue;
        } else {
    			if(map[by][bx] == 'H') {
            continue;
          } else if(map[ry][rx] == 'H') {
            return cnt;
          } else {
    				CURR_POS tmp_red, tmp_blue;
    				tmp_red.x = rx, tmp_red.y = ry;
            tmp_blue.x = bx, tmp_blue.y = by;
    				visited[ry][rx][by][bx] = 1;
            q_red.push(tmp_red);
            q_blue.push(tmp_blue);
            q_cnt.push(cnt);
    			}
        }
      }
    }
    return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, ans=-10;
	cin >> T;
	for (int i=0; i<T; i++){
    memset(map, '.', sizeof(map));
    memset(visited, 0, sizeof(visited));
    q_cnt = queue<int>();
    q_red = queue<CURR_POS>();
    q_blue = queue<CURR_POS>();
		InputData();//입력

		//여기서부터 작성
    q_red.push(init_red);
    q_blue.push(init_blue);
    q_cnt.push(0);
    visited[init_red.y][init_red.x][init_blue.y][init_blue.x] = 1;
    // cout << init_red.y << " " << init_red.x << "     " << init_blue.y << " " << init_blue.x << endl;
    ans = func();

		cout << ans << "\n";//출력
	}
	return 0;
}