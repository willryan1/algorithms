#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int mxN = 1e5;
int n, m;
vector<int> adj[mxN];
bool vis[mxN];
int prevNode[mxN];
vector<int> sol;
 
void dfs(int st, int p) {
    prevNode[st] = p;
    vis[st] = true;
    for(int nb : adj[st]) {
        if(nb == p) continue;
        if(vis[nb]) {
            sol.push_back(nb);
            int current = st;
            while(current != nb) {
                sol.push_back(current);
                current = prevNode[current];
            }
            sol.push_back(nb);
            cout << sol.size() << '\n';
            for(int i = 0; i < sol.size(); i++) {
                cout << sol[i] + 1 << " ";
            }
            exit(0);
        }
        dfs(nb, st);
    }
}
 
int main() {
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i, -1);
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
