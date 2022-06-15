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
#define MAXN (9)
int sudoku[MAXN][MAXN];
int hori[MAXN][MAXN];
int verti[MAXN][MAXN];
int squa[MAXN][MAXN];
int emptyCnt;
void InputData(){
  for (int r=0; r<MAXN; r++){
    for (int c=0; c<MAXN; c++){
      cin >> sudoku[r][c];
      if(sudoku[r][c] == 0) emptyCnt++;
      else {
        hori[r][sudoku[r][c]] = 1;
        verti[c][sudoku[r][c]] = 1;
        int squaIdx = (r/3) * 3 + (c/3);
        squa[squaIdx][sudoku[r][c]] = 1;
      }
    }
  }
}
void OutputData(){
    for (int r=0; r<MAXN; r++){
        for (int c=0; c<MAXN; c++){
            cout << sudoku[r][c] << " ";
        }
        cout << endl;
    }
}
bool flag;
void dfs(int idx) {
  if(flag) {
    int r = idx / 9; int c = idx % 9;
    if(idx == 81) {
      flag = false;
      OutputData();
      return;
    } else {
      if(sudoku[r][c] == 0) {
        for(int i = 1; i <= 9; i++) {
          int squaIdx = (r/3) * 3 + (c/3);
          if(hori[r][i] == 0 && verti[c][i] == 0 && squa[squaIdx][i] == 0) {
            hori[r][i] = 1; verti[c][i] = 1; squa[squaIdx][i] = 1;
            sudoku[r][c] = i;
            dfs(idx + 1);
            hori[r][i] = 0; verti[c][i] = 0; squa[squaIdx][i] = 0;
            sudoku[r][c] = 0;
          }
        }
      }
      else dfs(idx + 1);
    }
  }
}
int main(){
  emptyCnt = 0; flag = true;
  memset(hori, 0, sizeof(hori)); memset(verti, 0, sizeof(verti)); memset(squa, 0, sizeof(squa));
  InputData();//입력받는 부분
  //여기서부터 작성
  dfs(0);
  return 0;
}