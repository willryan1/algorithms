#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int m = 1e9 + 7;
const int mxN = 10e6;
int val[mxN + 1] = { 0 };
 
int dc_dp(int n) {
    val[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; (j <= 6) && (i-j >= 0); j++) {
            val[i] = (val[i] + val[i-j]) % m;
        }
    }
    return val[n];
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cout << dc_dp(n) << "\n";
    return 0;
}
