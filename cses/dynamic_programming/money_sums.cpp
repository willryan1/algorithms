#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, W = 0, amt = 0;
    cin >> n;
    int x[n];
    for(int i = 0; i < n; i++) {
        cin >> x[i];
        W += x[i];
    }
    vector<bool> value(W+1, false);
    value[0] = true;
    for(int i = 0; i < n; i++) {
        for(int j = W; j >= 0; j--) {
            if(value[j]) {
                if(!value[j + x[i]]) {
                    value[j + x[i]] = true;
                    amt++;
                }
            }
        }
    }
    cout << amt << '\n';
    for(int i = 1; i <= W; i++) {
        if(value[i])
            cout << i << " ";
    }
    return 0;
}
