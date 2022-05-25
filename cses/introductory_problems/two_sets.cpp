#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main() {
    ll n, i, j;
    cin >> n;
    ll sum = n * (n + 1) / 2;
    if(sum % 2 == 1) {
        cout << "NO" << "\n";
        return 0;
    }
    cout << "YES" << "\n";
    sum /= 2;
    i = 0, j = 0;
    vector<int> v1, v2;
    if(sum % n == 0) {
        v1.push_back(n);
        sum -= n;
        i++;
    }
    while(sum > 0) { 
        if(sum % n == 0) {
            v1.push_back(n-i);
            v1.push_back(i);
            sum -= n;
            i++;
        } else if(sum % (n+1) == 0) {
            v1.push_back(n-j);
            v1.push_back(++j);
            sum -= n+1;
            j++;
        }
    }
    sort(v1.begin(), v1.end());
    int index = 0;
    for(int i = 1; i <= n; i++) {
        if(v1[index] != i) {
            v2.push_back(i);
        } else {
            index++;
        }
    }
    cout << v1.size() << "\n";
    for(int i = 0; i < v1.size(); i++) cout << v1[i] << " ";
    cout << "\n" << v2.size() << "\n";
    for(int i = 0; i < v2.size(); i++) cout << v2[i] << " ";
    cout << "\n";
    return 0;
}
