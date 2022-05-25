#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int mxN = 5e3;
int x[mxN];
ll mx[mxN][mxN];
ll mi[mxN][mxN];
 
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i; j++) {
            if(i == 0) {
                mx[j][j] = x[j];
                mi[j][j] = 0;
                continue;
            }
            mx[j][j+i] = max(x[j] + mi[j+1][j+i], x[j+i] + mi[j][j+i-1]);
            mi[j][j+i] = min(mx[j+1][j+i], mx[j][j+i-1]);
        }
    }
    cout << mx[0][n-1];
    return 0;
}
