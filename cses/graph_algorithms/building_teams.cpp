#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int mxN = 1e5;
int n, m;
vector<int> adj[mxN];
// gc will represent the color of the vertices in the graph
// 0 = not visited
// 1 = blue
// 2 = red
int gc[mxN];
 
void bip(int st) {
    gc[st] = 1;
    queue<int> q;
    q.push(st);
    while(!q.empty()) {
        int s = q.front(); q.pop();
        for(int nb : adj[s]) {
            if(gc[nb]) {
                if(gc[nb] == gc[s]) {
                    cout << "IMPOSSIBLE\n";
                    exit(0);
                }
                continue;
            }
            if(gc[s] == 1)
                gc[nb] = 2;
            else
                gc[nb] = 1;
            q.push(nb);
        }
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
        if(!gc[i]) {
            bip(i);
        }
    }
    for(int i = 0; i < n; i++) {
        cout << gc[i] << " ";
    }
    cout << '\n';
    return 0;
}
