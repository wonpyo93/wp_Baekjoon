#include <iostream>
#include <string>
using namespace std;

string input, temp = "";
bool check;
int ans = 0;

int main() {
    cin >> input;
    for(int i = 0; i <= input.size(); i++) {
        if (input[i] == '+' || input[i] == '-' || input[i] == '\0') {
            if(check)
                ans -= stoi(temp);
            else
                ans += stoi(temp);
            temp = "";
            if (input[i] == '-')
                check = true;
        }
        else
            temp += input[i];
    }

    cout << ans;
    return 0;
}