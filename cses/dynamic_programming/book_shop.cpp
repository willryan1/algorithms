#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    int h[n], s[n];
    vector<int> cp(x+1, 0);
    for(int i = 0; i < n; i++)
        cin >> h[i];
    for(int i = 0; i < n; i++)
        cin >> s[i];
    for(int i = 0; i < n; i++) {
        for(int j = x; j >= h[i]; j--) {
            cp[j] = max(cp[j], cp[j - h[i]] + s[i]);
        }
    }
    cout << cp[x];
    return 0;
}
