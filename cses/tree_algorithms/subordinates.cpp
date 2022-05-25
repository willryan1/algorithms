#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int mxN = 2e5;
vector<int> adj[mxN];
int n;
int sub[mxN];
 
void dfs(int s, int e) {
    sub[s] = 0;
    for(auto u : adj[s]) {
        if(u == e) continue;
        sub[s]++;
        dfs(u, s);
        sub[s] += sub[u];
    }
}
 
int main() {
    cin >> n;
    int p;
    for(int i = 1; i < n; i++) {
        cin >> p; p--;
        adj[p].push_back(i);
    }
    dfs(0, -1);
    for(int i = 0; i < n; i++) {
        cout << sub[i] << " ";
    }
    return 0;
}
