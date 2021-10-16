//틀린 해답
#include <iostream>
#include <math.h>
#define endl '\n'
using namespace std;

int arr[6][3];

int solve() {
        //1. 각 row의 합이 5인지 확인
        int sum;
        for(int i = 0; i < 6; i++) {
            sum = 0;
            for(int j = 0; j < 3; j++) {
                sum += arr[i][j];
            }
            if(sum != 5)
                return 0;
        }

        //2. 무승부가 가능한 무승부인지 확인
        int draw = 0;
        for(int i = 0; i < 6; i++) {
            if(draw == 0)
                draw += arr[i][1];
            else
                draw = abs(draw - arr[i][1]);
        }
        if(draw != 0)
            return 0;

        //3. 승과 패의 합이 같은지 확인
        int win = 0, lose = 0;
        for(int i = 0; i < 6; i++) {
            win += arr[i][0];
            lose += arr[i][2];
        } 
        if(win != lose)
            return 0;
        
        return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T = 4;
    while(T--) {
        for(int i = 0; i < 6; i++)
            for(int j = 0; j < 3; j++)
                cin >> arr[i][j];

        cout << solve() << " ";
    }
    return 0;
}