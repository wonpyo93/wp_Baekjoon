#include <iostream>
#include <algorithm>
using namespace std;

int r, c;
int map[1500][1500];
int l_d[800][800];
int l_u[800][800];
int r_d[800][800];
int r_u[800][800];

int main() {
    cin >> r >> c;
    
    for(int i = 1; i < r+1; i++)
        for(int j = 1; j < c+1; j++)
            scanf("%1d", &map[i][j]);

    for(int i = 1; i < r+1; i++)
        for(int j = 1; j < c+1; j++)
            if(map[i][j] == 1) {
                l_u[i][j] = l_u[i-1][j-1] + 1;
                r_u[i][j] = r_u[i-1][j+1] + 1;
            }

    for(int i = r; i > 0; i--)
        for(int j = 1; j < c+1; j++)
            if(map[i][j] == 1) {
                l_d[i][j] = l_d[i+1][j-1] + 1;
                r_d[i][j] = r_d[i+1][j+1] + 1;
            }

    int s = 0;
    for(int i = 1; i < r+1; i++)
        for(int j = 1; j < c+1; j++) {
            for(int k = 1; k < min(l_d[i][j], r_d[i][j])+1; k++)
                if(map[i + 2*(k-1)][j] && l_u[i + 2*(k-1)][j] >= k && r_u[i + 2*(k-1)][j] >= k)
                    s = max(s, k);
            for(int k = 1; k < min(r_u[i][j], r_d[i][j])+1; k++)
                if(map[i][j + 2*(k-1)] && l_u[i][j + 2*(k-1)] >= k && l_d[i][j + 2*(k-1)] >= k)
                    s = max(s, k);
        }
    cout << s;    
    return 0;
}