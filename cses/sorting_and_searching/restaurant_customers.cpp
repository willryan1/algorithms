#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main() {
    int n;
    cin >> n;
    set<array<int, 2>> s;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        s.insert({a, 1});
        s.insert({b, -1});
    }
    int cur = 0, ans = 0;
    for(array<int, 2> ar : s) {
        cur += ar[1];
        ans = max(cur, ans);
    }
    cout << ans << "\n";
    return 0;
}
