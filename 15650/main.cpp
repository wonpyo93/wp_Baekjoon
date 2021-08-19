#include <iostream>
using namespace std;
#define MAX 8
 
int map[MAX], count, index, N, M;;
bool visited[MAX];

void printAnswer() {
    for(int i = 0; i < N; i++)
        if(visited[i])
            cout << map[i] << " ";
    cout << '\n';
}
 
void dfs(int count, int index) {
    if (count == M) {
        printAnswer();
        return;
    }
 
    for (int i = index; i < N; i++) {
        if (visited[i])
            continue;
        visited[i] = true;
 
        dfs(count + 1, i + 1);
        visited[i] = false;
    }
}

int main(){
    cin >> N >> M;
 
    for (int i = 0; i < N; i++) {
        map[i] = i + 1;
        visited[i] = false;
    }
    dfs(0, 0);
}
