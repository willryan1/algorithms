#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll msf = 0, ans = INT_MIN;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        msf = max<long long int>(msf + x, x);
        ans = max<long long int>(msf, ans);
    }
    cout << ans;
}
