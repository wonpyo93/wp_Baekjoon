#include<iostream>
using namespace std;
int N, M;
 
int gcd(int a, int b) {
	if(a%b == 0)
		return b;
	else
		return gcd(b, a % b);
}
 
int main() {
	cin >> N >> M;
	cout << M - gcd(N, M);
}