#include <iostream>
#define endl '\n'
using namespace std;

int arr[3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int sum = 0;

    for(int i = 0; i < 3; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    if(sum != 180) {
        cout << "Error" << endl;
        return 0;
    }
    else {
        if(arr[0] == arr[1] && arr[1] == arr[2]) {
            cout << "Equilateral" << endl;
            return 0;
        }

        if(arr[0] == arr[1] || arr[1] == arr[2] || arr[2] == arr[0]) {
            cout << "Isosceles" << endl;
            return 0;
        }
        cout << "Scalene" << endl;
    }
    return 0;
}