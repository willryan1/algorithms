#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int mxN = 2e5;
int x, n, p[mxN];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> x >> n;
    set<int> s;
    map<int, int> m;
    s.insert(0);
    s.insert(x);
    m[x] = 1;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        auto it = s.lower_bound(p[i]);
        int r = *it;
        --it;
        int l = *it;
        m[r-l]--;
        if(!m[r-l]) {
            m.erase(r-l);
        }
        s.insert(p[i]);
        m[r-p[i]]++;
        m[p[i]-l]++;
        cout << ((--m.end())->first) << " ";
    }
    return 0;
}
