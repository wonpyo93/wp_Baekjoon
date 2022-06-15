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
int N, M;
int A[10000 + 10]; //N1
int B[10000 + 10]; //N2
int L[10000 + 10]; //L
int links[110][110];
int total_dist[110];
int paths[110];
vector<int> toCheck;
void InputData(){
    cin >> N >> M;
    for (int i = 0; i<M; i++){
        cin >> A[i] >> B[i] >> L[i];
    }
}
struct DATA {
  int at = -1, cost = -1;
};
void getCheckPath(int p) {
  if(p == 0) {
    return;
  } else {
    getCheckPath(paths[p]);
    // cout << p << " ";
    toCheck.push_back(p);
  }
}
void BFS(){
  memset(total_dist, INF, sizeof(total_dist));
  queue<DATA> q;
  DATA init; init.at = 1; init.cost = 0;
  q.push(init); total_dist[1] = 0;
  //start BFS
  while(!q.empty()) {
    DATA tmp = q.front(); q.pop();
    // cout << "size : " << q.size() << endl;
    for(int i = 0; i < N + 1; i++) {
      if(links[tmp.at][i] > 0) {
        //there is a link, so try add to queue if lower
        int nowCost = tmp.cost + links[tmp.at][i];
        if(nowCost < total_dist[i]) {
          DATA toAdd; toAdd.at = i; toAdd.cost = nowCost;
          total_dist[i] = nowCost;
          // cout << "  " << toAdd.at << " " << toAdd.cost << endl;
          paths[i] = tmp.at;
          q.push(toAdd);
        }
      }
    }
  }
  
}
int main(){
  int ans = -1;
  InputData();// 입력받는 부분
  // 여기서부터 작성
  //initialize links
  memset(links, 12345, sizeof(links));
  for(int i = 0; i < M; i++) {
    int a = A[i], b = B[i];
    // cout << a << " " << b << endl;
    links[A[i]][B[i]] = min(L[i],links[A[i]][B[i]]);
    links[B[i]][A[i]] = min(L[i],links[A[i]][B[i]]);
  }
  BFS();
  int shortest_new = -1;
  int shortest_original = total_dist[N];
  getCheckPath(paths[N]); toCheck.push_back(N);
  for(int i = 0; i < toCheck.size() - 1; i++) {
    // cout << toCheck[i] << " " << toCheck[i+1] << endl;
    int toRevert = links[toCheck[i]][toCheck[i+1]];
    links[toCheck[i]][toCheck[i+1]] *=2;
    links[toCheck[i+1]][toCheck[i]] *=2;
    BFS();
    shortest_new = max(shortest_new, total_dist[N]);
    // cout << "shortest_new : " << shortest_new << endl;
    links[toCheck[i]][toCheck[i+1]] = toRevert;
    links[toCheck[i+1]][toCheck[i]] = toRevert;
  }
  ans = shortest_new - shortest_original;
  cout << ans << endl;// 출력하는 부분
  return 0;
}