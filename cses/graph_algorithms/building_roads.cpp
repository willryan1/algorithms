#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int mxN = 1e5;
int n, m;
bool visited[mxN];
vector<int> adj[mxN];
vector<int> cc[mxN];
 
void dfs(int c, int comp) {
    if(visited[c]) return;
    visited[c] = true;
    cc[comp].push_back(c);
    for(int nb : adj[c]) {
        dfs(nb, comp);
    }
}
 
int main() {
    int ans = 0;
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, ans++);
        }
    }
    cout << ans-1 << '\n';
    for(int i = 0; i < ans-1; i++) {
        cout << cc[i].back() + 1 << " " << cc[i+1][0] + 1 << '\n';
    }
    return 0;
}
