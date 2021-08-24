#include <iostream>
#include <string.h>
using namespace std;

int T, N, x[101], start, finish;

void reverse(int arr[], int start, int end) {
    while(start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}    

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    cin >> T;
    for(int t = 0; t < T; t++) {
        string P;
        cin >> P;
        cin >> N;
        start = 0; finish = N - 1;
        for(int i = 0; i < N; i++)
            cin >> x[i];
        for(int p = 0; p < P.length(); p++) {
            if(P[p] == 'R') {
                if(p + 1 < P.length() && P[p+1] == 'R') {
                    p++;
                    continue;
                }
                else {

                }
            }
        }
    }
}