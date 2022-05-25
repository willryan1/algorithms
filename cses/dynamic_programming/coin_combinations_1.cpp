#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int m = 1e9 + 7;
 
int cc(int n, set<int> coins) {
    if(n == 0) return 1;
    int sol = 0;
    for(int coin : coins) {
        if(n - coin >= 0)
            sol = (sol + cc(n - coin, coins)) % m;
    }
    return sol;
}
 
int cc_dp(int n, set<int> coins) {
    vector<int> value(n+1, 0);
    value[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int coin : coins) {
            if(i - coin >= 0)
                value[i] = (value[i] + value[i-coin]) % m;
        }
    }
    return value[n];
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
    cout << cc_dp(x, coins);
    return 0;
}
