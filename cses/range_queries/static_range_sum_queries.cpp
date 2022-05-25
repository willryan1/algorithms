#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int mxN = 2e5 + 1;
ll pre[mxN];
int n, q;
 
int main() {
    cin >> n >> q;
    int a, b;
    for(int i = 1; i <= n; i++) {
        cin >> pre[i];
        pre[i] += pre[i-1];
    }
    for(int i = 0; i < q; i++) {
        cin >> a >> b;
        cout << pre[b] - pre[a - 1] << " ";
    }
    return 0;
}
