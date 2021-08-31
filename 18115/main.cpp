#include <iostream>
#include <queue>
using namespace std;
int num, tmp, N, arr[1000001];
deque<int> Q;

int main() {
    num = 1;
    cin >> N;
    for(int i = N; i >= 1; i--)
        cin >> arr[i];
    for(int i = 1; i <= N; i++) {
        if(arr[i] == 1)
            Q.push_front(num);
        else if(arr[i] == 2) {
            tmp = Q.front();
            Q.pop_front();
            Q.push_front(num);
            Q.push_front(tmp);
        }
        else
            Q.push_back(num);
        num++;
    }

    //range-based for loop
    for(auto c : Q)
        cout << c << ' ';
    
    return 0;
}