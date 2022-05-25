#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main() {
    int n, m, k, ans = 0;
    cin >> n >> m >> k;
    int apps[n], aparts[m];
    for(int i = 0 ; i < n; i++)
        cin >> apps[i];
    for(int i = 0; i < m; i++)
        cin >> aparts[i];
    sort(apps, apps + n);
    sort(aparts, aparts + m);
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(aparts[j] < apps[i] - k) {
            j++;
            continue;
        } else if(aparts[j] <= apps[i] + k) {
            ans++;
            j++;
        }
        i++;
    }
    cout << ans << "\n";
    return 0;
}
