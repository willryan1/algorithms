#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int m = 1e9 + 7;
 
int cc_dp(int n, set<int> coins) {
    vector<int> value(n+1, 0);
    value[0] = 1;
    for(int i = 0; i <= n; i++) {
        for(int c : coins) {
            if(i - c >= 0) {
                value[i] = (value[i] + value[i-c]) % m;
            }
        }
    }
    return value[n];
}
 
int cc_dp2(int n, set<int> coins) {
    vector<int> value(n+1, 0);
    value[0] = 1;
    for(int c : coins) {
        for(int i = 0; i <= n; i++) {
            if(i - c >= 0) {
                value[i] = (value[i] + value[i-c]) % m;
            }
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
    cout << cc_dp2(x, coins);
    return 0;
}
