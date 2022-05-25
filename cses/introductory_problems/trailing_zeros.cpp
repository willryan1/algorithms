#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main() {
    int n, sol = 0;
    cin >> n;
    for(int i = 5; i <= n; i *= 5) {
        sol += n / i;
    }
    cout << sol << "\n";
    return 0;
}
