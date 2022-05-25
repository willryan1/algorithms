#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int mxN = 1e5;
int n, m;
vector<pair<ll, ll> > adj1[mxN];
ll dist1[mxN];
 
void dijkstra(int st, vector<pair<ll, ll> > adj[mxN], ll d[mxN]) {
    memset(d, 0x3f, sizeof(dist1));
    d[st] = 0;
    bool vis[mxN] = { false };
    priority_queue<pair<ll, ll> > pq;
    pq.push(make_pair(0, st));
    while(!pq.empty()) {
        ll s = pq.top().second; pq.pop();
        if(vis[s]) continue;
        vis[s] = true;
        for(auto u : adj[s]) {
            ll ele = u.first;
            ll weight = u.second;
            if(d[s] + weight < d[ele]) {
                d[ele] = d[s] + weight;
                pq.push(make_pair(-d[ele], ele));
            }
        }
    }
}
 
int main() {
    cin >> n >> m;
    ll a, b, c;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c, a--, b--;
        adj1[a].push_back(make_pair(b, c));
    }
    dijkstra(0, adj1, dist1);
    for(int i = 0; i < n; i++) {
        cout << dist1[i] << " ";
    }
    return 0;
}
