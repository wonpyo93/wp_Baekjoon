#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
#include <functional>
#include <map>
using namespace std;

map<string, int> Map;
struct D {
  string word;
  vector<int> idx;
};

int N;
int cnt = 1;
char S[10000+10][20+10];
D arr[10000+10];
bool uniq = true;
void InputData(){
  cin >> N;
  for (int i=0; i<N; i++){
    cin >> S[i];
    if(!Map[S[i]]) {
      Map[S[i]] = cnt++;
      arr[Map[S[i]]].word = S[i];
    } else {
      uniq = false;
    }
    arr[Map[S[i]]].idx.push_back(i+1);
  }
}

int main(){
  InputData();// 입력받는 부분

  // 여기서부터 작성
  if(uniq)
    cout << "unique" << endl;
  else {
    int tmp = 1;
    while(tmp < cnt) {
      if(arr[tmp].idx.size() != 1) {
        cout << arr[tmp].word;
        for(int i = 0; i < arr[tmp].idx.size(); i++) {
          cout << " " << arr[tmp].idx[i];
        }
        cout << endl;
      }
      tmp++;
    }
  }
  return 0;
}