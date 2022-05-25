#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main() {
    ll n, a, b;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        if((a+b)%3==0 && 2*a >= b && 2*b >= a) 
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    return 0;
}
