#include <iostream>
#include <algorithm>
using namespace std;
int N, ans;

int main() {
    cin >> N;
    int map[N+1], two[N+1], five[N+1], count_two = 0, count_five = 0;
    for(int i = 1; i < N + 1; i++) {
        map[i] = i;
        two[i] = 0;
        five[i] = 0;
    }
    for(int i = 1; i < N + 1; i++) {
        while(map[i] % 2 == 0) {
            map[i] = map[i] / 2;
            two[i]++;
        }
        while(map[i] % 5 == 0) {
            map[i] = map[i] / 5;
            five[i]++;
        }
    }
    for(int i = 1; i < N + 1; i++) {
        count_two = count_two + two[i];
        count_five = count_five + five[i];
    }
    ans = min(count_two, count_five);
    cout << ans;
    return 0;
}