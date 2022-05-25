#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int n, p[20];
 
int main() {
    cin >> n;
    ll ps = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        ps += p[i];
    }
    for(int b = 0; b < 1 << n; b++) {
        ll ss = 0;
        for(int i = 0; i < n; i++) {
            if(b & (1<<i)) ss += p[i];
        }
        if(ss <= ps / 2) {
            ans = max(ans, ss);
        }
    }
    cout << ps - 2*ans;
    return 0;
}
