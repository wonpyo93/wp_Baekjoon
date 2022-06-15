#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int A[5+10][5+10];
int B[25+10];
void InputData(){
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            cin >> A[i][j];
        }
    }
    for (int i=0; i<25; i++){
        cin >> B[i];
    }
}

int main(){
  int ans = 0;
  InputData();// 입력받는 부분

  // 여기서부터 작성
  vector<int> ha, hb, hc, hd, he, va, vb, vc, vd, ve, da, db;
  int hac=0, hbc=0, hcc=0, hdc=0, hec=0, vac=0, vbc=0, vcc=0, vdc=0, vec=0, dac=0, dbc=0;
  for(int i = 0; i < 5; i++) {
    ha.push_back(A[0][i]);
    hb.push_back(A[1][i]);
    hc.push_back(A[2][i]);
    hd.push_back(A[3][i]);
    he.push_back(A[4][i]);
    va.push_back(A[i][0]);
    vb.push_back(A[i][1]);
    vc.push_back(A[i][2]);
    vd.push_back(A[i][3]);
    ve.push_back(A[i][4]);
    da.push_back(A[i][i]);
    db.push_back(A[4-i][i]);
  }
  int i;
  for(i = 0; i < 25; i++) {
    if(find(ha.begin(), ha.end(), B[i]) != ha.end()) {
      hac++;
      if(hac == 5) ans++;
    }
    if(find(hb.begin(), hb.end(), B[i]) != hb.end()) {
      hbc++;
      if(hbc == 5) ans++;
    }
    if(find(hc.begin(), hc.end(), B[i]) != hc.end()) {
      hcc++;
      if(hcc == 5) ans++;
    }
    if(find(hd.begin(), hd.end(), B[i]) != hd.end()) {
      hdc++;
      if(hdc == 5) ans++;
    }
    if(find(he.begin(), he.end(), B[i]) != he.end()) {
      hec++;
      if(hec == 5) ans++;
    }
    if(find(va.begin(), va.end(), B[i]) != va.end()) {
      vac++;
      if(vac == 5) ans++;
    }
    if(find(vb.begin(), vb.end(), B[i]) != vb.end()) {
      vbc++;
      if(vbc == 5) ans++;
    }
    if(find(vc.begin(), vc.end(), B[i]) != vc.end()) {
      vcc++;
      if(vcc == 5) ans++;
    }
    if(find(vd.begin(), vd.end(), B[i]) != vd.end()) {
      vdc++;
      if(vdc == 5) ans++;
    }
    if(find(ve.begin(), ve.end(), B[i]) != ve.end()) {
      vec++;
      if(vec == 5) ans++;
    }
    if(find(da.begin(), da.end(), B[i]) != da.end()) {
      dac++;
      if(dac == 5) ans++;
    }
    if(find(db.begin(), db.end(), B[i]) != db.end()) {
      dbc++;
      if(dbc == 5) ans++;
    }

    //cout << hac << " " << hbc << " " << hcc << " " << hdc << " " << hec << "      " << vac << " " << vbc << " " << vcc << " " << vdc << " " << vec << "      " << dac << " " << dbc << endl; 
    if(ans >= 3)
      break;
  }
  

  cout << i+1 << endl;// 출력하는 부분
  return 0;
}