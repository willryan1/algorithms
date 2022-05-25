// CSES - High Score
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int mxN = 2500;
int n, m;
tuple<int, int, int> edges[5000];
ll dist[mxN];
vector<int> adj[mxN];
vector<int> adj1[mxN];
bool vis[mxN];
bool vis2[mxN];
 
void dfs(int c) {
    if(vis[c]) return;
    vis[c] = true;
    for(int nb : adj[c]) {
        dfs(nb);
    }
}
 
void dfs2(int c) {
    if(vis2[c]) return;
    vis2[c] = true;
    for(int nb : adj1[c]) {
        dfs2(nb);
    }
}
 
int main() {
    cin >> n >> m;
    int a, b, x;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> x, a--, b--;
        edges[i] = make_tuple(a, b, x);
        adj1[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(dist, 0xc0, sizeof(dist));
    dist[0] = 0;
    for(int i = 0; i < n-1; i++) {
        for(auto t : edges) {
            int a, b, w;
            tie(a, b, w) = t;
            dist[b] = max(dist[b], dist[a] + w);
        }
    }
    vector<int> changed;
    // Check for cycle
    for(auto t : edges) {
        int a, b, w;
        tie(a, b, w) = t;
        if(dist[a] + w > dist[b]) {
            changed.push_back(a);
//            changed.push_back(b);
        }
    }
    dfs(n-1);
    dfs2(0);
    for(int i = 0; i < changed.size(); i++) {
        if(vis[changed[i]] && vis2[changed[i]]){
            cout << -1;
            return 0;
        }
    }
    cout << dist[n-1];
    return 0;
}
