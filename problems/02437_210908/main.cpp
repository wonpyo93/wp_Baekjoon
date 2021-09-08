#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define ll long long
using namespace std;

int N;
ll tmp, sum;
vector<ll> vec;

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        vec.push_back(tmp);
    }
    
    sort(vec.begin(), vec.end());
    
    //print sorted
    // for(int i = 0; i < vec.size(); i++)
    //     cout << vec[i] << " ";
    // cout << endl;

    sum = 1;
    if(vec[0] != 1)
        cout << 1;
    else {
        for(int i = 1; i < N; i++) {
            if(vec[i] > sum + 1) {
                // cout << vec[i] << " " << sum + 1 << endl;
                break;
            }
            sum += vec[i];
            // cout << "sum = " << sum << endl;
        }
        cout << sum + 1;
    }
    return 0;
}