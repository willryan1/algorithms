#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int m = 1e9 + 7;
 
int main() {
    int n;
    cin >> n;
    string board[n];
    int grid[n][n];
    for(int i = 0; i < n; i++)
        cin >> board[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 && j == 0 && board[i][j] != '*') {
                grid[i][j] = 1;
                continue;
            }
            grid[i][j] = 0;
            if(board[i][j] == '*')
                continue;
            if(i)
                grid[i][j] += grid[i-1][j];
            if(j)
                grid[i][j] += grid[i][j-1];
            grid[i][j] %= m;
        }
    }
    cout << grid[n-1][n-1];
    return 0;
}
