#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int mxN = 1e5;
int n, m;
bool visited[mxN];
vector<int> adj[mxN];
int prevNode[mxN];
 
bool bfs(int c) {
    visited[c] = true;
    queue<vector<int>> q;
    adj[c].push_back(c);
    q.push(adj[c]);
    while(!q.empty()) {
        vector<int> s = q.front(); q.pop();
        for(int ad : s) {
            if(visited[ad]) continue;
            prevNode[ad] = s.back();
            if(ad == n-1) return true;
            visited[ad] = true;
            adj[ad].push_back(ad);
            q.push(adj[ad]);
        }
    }
    return false;
}
 
int main() {
    bool ans;
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ans = bfs(0);
    if(!ans) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> sol;
        int end = n-1;
        sol.push_back(end);
        while(end != 0) {
            sol.push_back(prevNode[end]);
            end = prevNode[end];
        }
        reverse(sol.begin(), sol.end());
        cout << sol.size() << '\n';
        for(int i = 0; i < sol.size(); i++) {
            cout << sol[i] + 1 << " ";
        }
        cout << '\n';
    }
    return 0;
}
