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
#define MAXN (20)
int N, B;
int H[MAXN + 10];
int visited[MAXN + 10];
int map[MAXN + 10];
int tmp;
vector<int> v;
bool flag;
void InputData(){
    cin >> N >> B;
    for (int i=0; i<N; i++){
        cin >> H[i];
    }
}
void dfs(int idx, int sum) {
  if(!flag) {
    // cout << "dfs on " << idx << ", " << sum << endl;
    if(sum >= B) {
      tmp = min(tmp, sum);
      if(tmp == B) flag = true;
      return;
    }
    // if(idx == N) {
    //   for (int i = 0; i < N; i++)
    //     cout << map[i] << " ";
    //   cout << "\n";
    //   return;
    // }
    for (int i = idx; i < N; i++) {
      if (visited[i])
        continue;
      visited[i] = true;
      // map[idx] = v[i];
      dfs(i + 1, sum + H[i]);
      visited[i] = false;
    }
  }
}

int main(){
  int T, ans = -1;
  cin >> T;
  for (int t=1; t<=T; t++){
    InputData();//입력받는 부분

    //여기서부터 작성
    v.clear();
    v.resize(N);
    flag = false;
    memset(visited, 0, sizeof(visited));
    // memset(map, 0, sizeof(map));
    // sort(H, H + N, greater<int>());
    tmp = 123456789;
    // for(int i = 0; i < N; i++) {
    //   v[i] = H[i];
    // }
    dfs(0, 0);

    cout << tmp - B << endl;
  }
  return 0;
}