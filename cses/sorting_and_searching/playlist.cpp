#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int k[n];
    int ans = 0;
    map<int, int> m;
    for(int i = 0; i < n; i++) {
        cin >> k[i];
        m[k[i]] = -1;
    }
    int i = 0;
    for(int j = 0; j < n; j++) {
        i = max(i, m[k[j]] + 1);
        ans = max(j - i + 1, ans);
        m[k[j]] = j;
    }
    cout << ans;
    return 0;
}

