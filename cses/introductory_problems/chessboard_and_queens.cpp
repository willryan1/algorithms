#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int ans = 0;
int cols[8] = {0};
int diag1[14] = {0};
int diag2[14] = {0};
string board[8];
 
void cQueens(int y) {
    if(y == 8) {
        ans++;
        return;
    }
    for(int x = 0; x < 8; x++) {
        if(cols[x] || diag1[x+y] || diag2[x-y+7] || board[y].at(x) == '*') continue;
        cols[x] = diag1[x+y] = diag2[x-y+7] = 1;
        cQueens(y+1);
        cols[x] = diag1[x+y] = diag2[x-y+7] = 0;
    }
}
 
int main() {
    for(int i = 0; i < 8; i++)
        cin >> board[i];
    cQueens(0);
    cout << ans << "\n";
    return 0;
}
