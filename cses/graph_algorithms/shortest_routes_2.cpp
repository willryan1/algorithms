// CSES - Shortest Routes II
 
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int mxN = 500;
int n, m, q;
ll dist[mxN][mxN];
 
int main() {
    cin >> n >> m >> q;
    int a, b, c;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c, a--, b--;
        if(dist[a][b] && dist[a][b] < c) continue;
        dist[a][b] = c;
        dist[b][a] = c;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                dist[i][j] = 0;
                continue;
            }
            if(dist[i][j]) continue;
            else dist[i][j] = -1;
        }
    }
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dist[i][k] == -1 || dist[k][j] == -1) continue;
                if(dist[i][j] == -1) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    continue;
                }
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    vector<ll> output;
    for(int i = 0; i < q; i++) {
        cin >> a >> b, a--, b--;
        output.push_back(dist[a][b]);
    }
    for(int i = 0; i < output.size(); i++) {
        cout << output[i] << '\n';
    }
    return 0;
}
