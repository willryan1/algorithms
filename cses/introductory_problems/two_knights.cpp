#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main() {
    int n;
    cin >> n;
    for(int k = 1; k <=n; k++) {
        ll tot = k*k, c2 = tot * (tot-1) / 2;
        if(k > 2) {
            c2 -= 4 * (k - 1) * (k - 2);
        }
        cout << c2 << "\n";
    }
    return 0;
}
