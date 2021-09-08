#include <iostream>
#include <algorithm>
using namespace std;

int N, M, map[1001][1001], ans, temp;

int calc(int y, int x, int choice) {
    if(choice == 0)
        return map[y][x] + map[y][x+1] + map[y][x+2] + map[y][x+3];
    if(choice == 1)
        return map[y][x] + map[y][x+1] + map[y][x+2] + map[y+1][x+2];
    if(choice == 2)
        return map[y][x] + map[y][x+1] + map[y][x+2] + map[y+1][x+1];
    if(choice == 3)
        return map[y][x] + map[y][x+1] + map[y][x+2] + map[y+1][x];
    if(choice == 4)
        return map[y][x] + map[y][x+1] + map[y+1][x+1] + map[y+1][x+2];
    if(choice == 5)
        return map[y][x] + map[y][x+1] + map[y+1][x+1] + map[y+2][x+1];
    if(choice == 6)
        return map[y][x] + map[y][x+1] + map[y+1][x+1] + map[y+1][x];
    if(choice == 7)
        return map[y][x] + map[y][x+1] + map[y+1][x] + map[y+2][x];
    if(choice == 8)
        return map[y][x] + map[y][x+1] + map[y+1][x] + map[y+1][x-1];
    if(choice == 9)
        return map[y][x] + map[y+1][x] + map[y+1][x+1] + map[y+1][x+2];
    if(choice == 10)
        return map[y][x] + map[y+1][x] + map[y+1][x+1] + map[y+2][x+1];
    if(choice == 11)
        return map[y][x] + map[y+1][x] + map[y+1][x+1] + map[y+2][x];
    if(choice == 12)
        return map[y][x] + map[y+1][x] + map[y+2][x] + map[y+2][x+1];
    if(choice == 13)
        return map[y][x] + map[y+1][x] + map[y+2][x] + map[y+3][x];
    if(choice == 14)
        return map[y][x] + map[y+1][x] + map[y+1][x-1] + map[y+2][x-1];
    if(choice == 15)
        return map[y][x] + map[y+1][x] + map[y+1][x-1] + map[y+1][x-2];
    if(choice == 16)
        return map[y][x] + map[y+1][x] + map[y+2][x] + map[y+2][x-1];
    if(choice == 17)
        return map[y][x] + map[y+1][x] + map[y+2][x] + map[y+1][x-1];
    if(choice == 18)
        return map[y][x] + map[y+1][x] + map[y+1][x+1] + map[y+1][x-1];
    else return 0;
}


int main() {
    ans = temp = 0;
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> map[i][j];
            
    // cout << "0\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\t11\t12\t13\t14\t15\t16\t17\t18" << endl;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int p[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
            if(j == 0) p[8] = p[14] = p[15] = p[16] = p[17] = p[18] = 0;
            else if(j == 1) p[15] = 0;

            if(j == M - 1) p[0] = p[1] = p[2] = p[3] = p[4] = p[5] = p[6] = p[7] = p[8] = p[9] = p[10] = p[11] = p[12] = p[18] = 0;
            else if(j == M - 2) p[0] = p[1] = p[2] = p[3] = p[4] = p[9] = 0;
            else if(j == M - 3) p[0] = 0;

            if(i == N - 1) p[1] = p[2] = p[3] = p[4] = p[5] = p[6] = p[7] = p[8] = p[9] = p[10] = p[11] = p[12] = p[13] = p[14] = p[15] = p[16] = p[17] = p[18] = 0;
            else if(i == N - 2) p[5] = p[7] = p[10] = p[11] = p[12] = p[13] = p[14] = p[16] = p[17] = 0;
            else if(i == N - 3) p[13] = 0;
            
            for(int k = 0; k < 19; k++) {
                if(p[k] == 1) {
                    ans = max(ans, calc(i, j, k));
                    // cout << calc(i, j, k) << "\t";
                }
                // else cout << "\t";
            }
            // cout << endl;
        }
    }
    cout << ans;

}