#include<bits/stdc++.h>
#include<array>
using namespace std;
 
#define ll long long
 
const int mxN = 1e3;
int n, m, previousStep[mxN][mxN];
string board[mxN];
char P[4] = {'D', 'R', 'U', 'L'};
int A[4] = {1, 0, -1, 0};
int B[4] = {0, 1, 0, -1};
 
bool bfs(int i, int j) {
    queue<array<int, 2> > q;
    array<int, 2> c = {i, j};
    q.push(c);
    while(!q.empty()) {
        array<int, 2> s = q.front(); q.pop();
        for(int k = 0; k < 4; k++) {
            if(s[0] + A[k] < 0 || s[1] + B[k] < 0 || s[0] + A[k] >= n || s[1] + B[k] >= m || board[s[0]+A[k]][s[1]+B[k]] == '#' || board[s[0]+A[k]][s[1]+B[k]] == 'A') {
                continue;
            }
            if(board[s[0]+A[k]][s[1]+B[k]] == 'B') {
                previousStep[s[0]+A[k]][s[1]+B[k]] = k;
                return true;
            }
            board[s[0]+A[k]][s[1]+B[k]] = '#';
            previousStep[s[0]+A[k]][s[1]+B[k]] = k;
            array<int, 2> current = {s[0]+A[k], s[1]+B[k]};
            q.push(current);
        }
    }
    return false;
}
 
int main() {
    bool ans;
    cin >> n >> m;
    array<int, 2> begin, end;
    for(int i = 0; i < n; i++)
        cin >> board[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'A') begin = {i, j};
            if(board[i][j] == 'B') end = {i, j};
        }
    }
    ans = bfs(begin[0], begin[1]);
    if(ans) {
        cout << "YES\n";
        vector<int> steps;
        while(end[0] != begin[0] || end[1] != begin[1]) {
            int p = previousStep[end[0]][end[1]];
            steps.push_back(p);
            end = {end[0] - A[p], end[1] - B[p]};
        }
        reverse(steps.begin(), steps.end());
        cout << steps.size() << '\n';
        for(int st : steps) {
            cout << P[st];
        }
        cout << '\n';
    }
    else {
        cout << "NO\n";
    }
    return 0;
}
