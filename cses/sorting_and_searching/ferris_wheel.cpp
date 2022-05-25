#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main() {
    int n, x, ans = 0;
    cin >> n >> x;
    int p[n];
    for(int i = 0; i < n; i++) 
        cin >> p[i];
    sort(p, p + n);
    int i = 0, j = n - 1;
    while(i < j) {
        if(p[i] + p[j] > x) j--;
        else {
            ans++;
            i++;
            j--;
        }
    }
    cout << n - ans << "\n";
    return 0;
}
