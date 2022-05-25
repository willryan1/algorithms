#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main() {
    int n;
    ll x, prev = -1, total = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        while(x < prev) {
            total++;
            x++;
        }
        prev = x;
    }
    cout << total << endl;
    return 0;
}
