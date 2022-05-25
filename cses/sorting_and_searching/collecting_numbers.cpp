#include <bits/stdc++.h>
using namespace std;
 
int n, c;
 
int main() {
    int ans = 0;
    map<int, int> m;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> c;
        m[c] = i;
    }
    int iv = 1;
    while(iv != n+1) {
        int prev = m[iv++];
        while(iv != n+1 && m[iv] > prev) {
            prev = m[iv++];
        }
        ans++;
    }
    cout << ans;
    return 0;
}
