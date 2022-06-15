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
#define MAXW (20)
int N;//도로의 개수
int W;//사건의 개수
struct POS{
	int r, c;//세로, 가로
};
POS pos[MAXW+10];//사건 좌표
int ans;
void InputData() {
	cin >> N;
	cin >> W;
	for (int i=0; i<W; i++){
		cin >> pos[i].r >> pos[i].c;
	}
}
int getDist(int aX, int aY, int bX, int bY) {
  int theX = aX - bX;
  if(theX < 0) theX = -theX;
  int theY = aY - bY;
  if(theY < 0) theY = -theY;
  return (theX + theY);
}
void dfs(int oneX, int oneY, int twoX, int twoY, int oneDist, int twoDist, int idx) {
  // cout << "dfs...\t" <<oneX<<"\t"<<oneY<<"\t"<<twoX<<"\t"<<twoY<<"\t"<<oneDist<<"\t"<<twoDist<<"\t"<<idx<<endl;
  if(idx == W) {
    ans = min(ans, oneDist + twoDist);
    return;
  }
  int byOne = getDist(oneX, oneY, pos[idx].r, pos[idx].c);
  int byTwo = getDist(twoX, twoY, pos[idx].r, pos[idx].c);
  dfs(pos[idx].r, pos[idx].c, twoX, twoY, oneDist + byOne, twoDist, idx + 1);
  dfs(oneX, oneY, pos[idx].r, pos[idx].c, oneDist, twoDist + byTwo, idx + 1);
  
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	InputData();//입력받는 부분

	//여기서부터 작성
  ans = INF;
  dfs(1,1,N,N,0,0,0);

	cout << ans << "\n";//출력하는 부분
	return 0;
}