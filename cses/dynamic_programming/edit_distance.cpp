#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
int distance(string a, string b) {
    if(a.length() == 0)
        return b.length();
    if(b.length() == 0) 
        return a.length();
    int i = distance(a, b.substr(0, b.length()-1)) + 1;
    int r = distance(a.substr(0, a.length()-1), b) + 1;
    int m = distance(a.substr(0, a.length()-1), b.substr(0, b.length()-1));
    if(a.back() != b.back()) m++;
    return min(i, min(r, m));
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string n, m;
    cin >> n >> m;
    int dp[n.size()+1][m.size()+1];
    for(int i = 0; i <= n.size(); i++)
        dp[i][0] = i;
    for(int i = 0; i <= m.size(); i++)
        dp[0][i] = i;
    for(int i = 1; i <= n.size(); i++) {
        for(int j = 1; j <= m.size(); j++) {
            dp[i][j] = 1e9;
            if(n[i-1] == m[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            dp[i][j] = min({dp[i][j-1], dp[i-1][j], dp[i][j]-1, dp[i-1][j-1]}) + 1;
        }
    }
    cout << dp[n.size()][m.size()];
    return 0;
}
