#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end(), [](auto &left, auto &right) {
        return left.second < right.second;
    });
    int last_e = INT_MAX, ans = 0;
    for(int i = 0; i < n; i++) {
        if(v[i].first >= last_e || v[i].second < last_e) {
            last_e = v[i].second;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
