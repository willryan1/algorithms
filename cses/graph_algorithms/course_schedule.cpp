#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int mxN = 1e5;
int n, m;
int state[mxN];
vector<int> adj[mxN];
 
void dfs(int s, vector<int>& ts) {
    if(state[s] == 1) {
        cout << "IMPOSSIBLE\n";
        exit(0);
    }
    if(state[s] == 2) return;
    state[s] = 1;
    for(int nb : adj[s]) {
        dfs(nb, ts);
    }
    state[s] = 2;
    ts.push_back(s);
}
 
int main() {
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b, a--, b--;
        adj[a].push_back(b);
    }
    vector<int> ts;
    for(int i = 0; i < n; i++) {
        dfs(i, ts);
    }
    reverse(ts.begin(), ts.end());
    for(int i = 0; i < ts.size(); i++) {
        cout << ts[i] + 1 << " ";
    }
    return 0;
}
