#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
int mc_dp(int x, set<int> coins) {
    vector<int> value(x+1, -1);
    value[0] = 0;
    for(int i = 1; i <= x; i++) {
        for(int c : coins) {
            if(i - c < 0) continue;
            int r = value[i-c];
            if(r >= 0 && value[i] >= 0) value[i] = min(value[i], r + 1);
            else if(r >= 0 && value[i] < 0) value[i] = r + 1;
        }
    }
    return value[x];
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x, c;
    cin >> n >> x;
    set<int> coins;
    for(int i = 0; i < n; i++) {
        cin >> c;
        coins.insert(c);
    }
    cout << mc_dp(x, coins);
    return 0;
}
