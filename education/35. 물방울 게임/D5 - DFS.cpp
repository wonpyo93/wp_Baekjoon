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
#define MAXN (100)
int A;
int N;
int W[MAXN+10];
int ans;
void InputData(){
    cin >> A >> N;
    for (int i=0; i<N; i++){
        cin >> W[i];
    }
}
void dfs(int idx, int sum, int cnt) {
  // cout << "dfs : " << idx << "\t" << sum << "\t" << cnt << "\t\t" << ans << endl;
  if(idx >= N) {
    // cout << "  idx >= N" << endl;
    ans = min(ans, cnt);
    return;
  }
  if(ans <= cnt) return;
  if(sum > W[idx]) { //consume
    dfs(idx + 1, sum + W[idx], cnt);
  } else { // try add or remove before
    if(sum > 1) {
      // cout << "  sum > 1" << endl;
      dfs(idx, sum + (sum - 1), cnt + 1);
    }
    // new road
    dfs(idx + 1, sum, cnt + 1);
  }
}

int main(){
  int t, T;
  cin >> T;
  for (t=1; t<=T; t++){
    memset(W, 0, sizeof(W));
    InputData();//입력받는 부분
    //여기서부터 작성
    ans = N;
    sort(W, W + N);
    dfs(0, A, 0);
    cout << "Case #" << t << ": " << ans << endl;//출력하는 부분
  }
  return 0;
}