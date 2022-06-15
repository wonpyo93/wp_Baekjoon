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

int P;
char N1[10000+10];
char N2[10000+10];
int L[10000+10];
char farm;
int sol;
void InputData(){
    cin >> P;
    for (int i=0; i<P; i++){
        cin >> N1[i] >> N2[i] >> L[i];
    }
}
struct DATA {
  int at = -1, cost = -1;
};

int main(){
  InputData();// 입력받는 부분

  // 여기서부터 작성
  int links[130][130]; // 65 ~ 122
  int total_dist[130];
  memset(links, 12345, sizeof(links));
  memset(total_dist, INF, sizeof(total_dist));
  //initialize links
  for(int i = 0; i < P; i++) {
    int a = N1[i], b = N2[i];
    // cout << a << " " << b << endl;
    links[N1[i]][N2[i]] = min(L[i],links[N1[i]][N2[i]]);
    links[N2[i]][N1[i]] = min(L[i],links[N1[i]][N2[i]]);
  }
  queue<DATA> q;
  DATA init; init.at = (int)'Z'; init.cost = 0;
  q.push(init); total_dist['Z'] = 0;
  //start BFS
  while(!q.empty()) {
    DATA tmp = q.front(); q.pop();
    // cout << "size : " << q.size() << endl;
    for(int i = 60; i < 130; i++) {
      if(links[tmp.at][i] > 0) {
        //there is a link, so try add to queue if lower
        int nowCost = tmp.cost + links[tmp.at][i];
        if(nowCost < total_dist[i]) {
          DATA toAdd; toAdd.at = i; toAdd.cost = nowCost;
          total_dist[i] = nowCost;
          // cout << "  " << toAdd.at << " " << toAdd.cost << endl;
          q.push(toAdd);
        }
      }
    }
  }
  sol = INF;
  for(int i = 65; i < 90; i++) {
    if(sol > total_dist[i]) {
      sol = total_dist[i];
      farm = i;
    }
  }
  cout << farm << " " << sol << endl;// 출력하는 부분
  return 0;
}