#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, length = 0;
    cin >> n;
    int x[n], dp[n+1];
    for(int i = 0; i < n; i++)
        cin >> x[i];
    for(int i = 0; i < n; i++) {
        if(i == 0 || x[i] >= dp[length-1]) {
            dp[length++] = x[i];
            continue;
        }
        int l = 0;
        int h = length -1;
        while(h > l) {
            int mid = l + ((h-l) / 2);
            if(x[i] < dp[mid]) 
                h = mid;
            else
                l = mid + 1;
        }
        dp[l] = x[i];
    }
    cout << length;
    return 0;
}
