#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int mxN = 1e3;
int n, m;
string board[mxN];
 
void dfs(int i, int j) {
    if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] == '#') {
        return;
    }
    board[i][j] = '#';
    dfs(i-1, j);
    dfs(i, j+1);
    dfs(i+1,j);
    dfs(i, j-1);
}
 
int main() {
    int ans = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> board[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == '.') {
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
