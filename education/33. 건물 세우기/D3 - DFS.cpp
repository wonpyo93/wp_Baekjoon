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

#define MAXN (10)
int N;
int cost[MAXN+10][MAXN+10];
int solpath[MAXN+10];//답 경로
int path[MAXN+10];
int visited[MAXN+10];
int ans;
void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> cost[i][j];
        }
    }
}
void OutputData(int sol){
    cout << sol << endl;
    for (int i=0; i<N; i++){
        cout << solpath[i] << " ";
    }
    cout << endl;
}
void dfs(int idx, int sum) {
  // for(int i = 0; i < idx; i++) cout << "\t";
  // cout << idx << "," << sum << endl;
  if(idx == N) {
    ans = sum;
    for(int i = 0; i < N; i++) {
      solpath[i] = path[i] + 1;
    }
    return;
  }
  for(int i = 0; i < N; i++) {
    if(visited[i]) continue;
    if(sum + cost[idx][i] > ans) continue;
    visited[i] = 1;
    path[idx] = i;
    dfs(idx + 1, sum + cost[idx][i]);
    visited[i] = 0;
    path[idx] = 0;
  }
}
int main(){
  InputData();//입력받는 부분

  //여기서부터 작성
  memset(visited, 0, sizeof(visited));
  ans = INF;
  dfs(0, 0);

  OutputData(ans);//출력하는 부분
  return 0;
}