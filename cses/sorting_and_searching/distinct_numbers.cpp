#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main() {
    int n, x;
    set<int> s;
    cin >> n;
    while(n--) {
        cin >> x;
        s.insert(x);
    }
    cout << s.size() << "\n";
    return 0;
}
