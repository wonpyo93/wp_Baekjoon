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
char map[5][10];
int H[] = {0,1,1,1,1,2,2,3,3,3,3,4};
int W[] = {4,1,3,5,7,2,6,1,3,5,7,4};
int sum[6];
int sumCnt[6];
int cal1[] = {0,3,0,2,4,0,2,0,1,1,1,3};
int cal2[] = {2,5,5,5,5,3,4,1,3,4,2,4};
int used[13];
int emptyz[12];
int emptyCnt;
void InputData(){
	for (int h=0; h<5; h++){
		cin >> map[h];
	}
}
void OutputData(){
	for (int h=0; h<5; h++){
		cout << map[h] << endl;
	}
}
int DFS(int n) {
  if(n >= emptyCnt) return 1;
  int idx = emptyz[n];
  int h = H[idx], w = W[idx], c1 = cal1[idx], c2 = cal2[idx];
  for(int k = 1; k <= 12; k++) {
    if(used[k] == 1) continue;
    if(sumCnt[c1] >= 3) {
      if(sum[c1] + k != 26) continue; //4개의 요소를 다 더한 경우 26
    } else {
      if(sum[c1] + k >= 26) continue;
    }
    if(sumCnt[c2] >= 3) {
      if(sum[c2] + k != 26) continue; //4개의 요소를 다 더한 경우 26
    } else {
      if(sum[c2] + k >= 26) continue;
    }
    used[k] = 1;
    sum[c1] += k; sumCnt[c1]++;
    sum[c2] += k; sumCnt[c2]++;
    map[h][w] = (char)(k - 1 + 'A');
    if(DFS(n + 1) == 1) return 1;
    used[k] = 0;
    sum[c1] -= k; sumCnt[c1]--;
    sum[c2] -= k; sumCnt[c2]--;
  }
  return 0;
}
void Solve() {
  //빈칸 찾고 sum배열 일부 완성하기
  emptyCnt = 0;
  for(int i = 0; i < 12; i++) {
    //12개 칸 확인
    int h = H[i], w = W[i];
    if(map[h][w] == 'x') {
      emptyz[emptyCnt++] = i;
    } else {
      int c1 = cal1[i], c2 = cal2[i];
      int k = map[h][w] - 'A' + 1;
      used[k] = 1;
      sum[c1] += k; sumCnt[c1]++;
      sum[c2] += k; sumCnt[c2]++;
    }
  }
  DFS(0);
}
int main(){
	InputData();//입력받는 부분

	//여기서부터 작성
  Solve();

	OutputData();//출력하는 부분
	return 0;
}