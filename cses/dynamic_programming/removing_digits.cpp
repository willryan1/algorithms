#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
vector<int> values(1e6+1, -1);
 
int rd(int n) {
    if(n == 0) return 0;
    int sol = INT_MAX;
    vector<int> digits;
    int num = n;
    while(num > 0) {
        digits.push_back(num % 10);
        num /= 10;
    }
    for(int digit : digits) {
        if(n - digit >= 0 && digit != 0)
            sol = min(sol, rd(n - digit) + 1);
    }
    return sol;
}
 
int rd_memo(int n) {
    if(n == 0) return 0;
    if(values[n] != -1) return values[n];
    int sol = INT_MAX;
    vector<int> digits;
    int num = n;
    while(num > 0) {
        digits.push_back(num % 10);
        num /= 10;
    }
    for(int digit : digits) {
        if(n - digit >= 0 && digit != 0)
            sol = min(sol, rd_memo(n - digit) + 1);
    }
    values[n] = sol;
    return sol;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cout << rd_memo(n);
    return 0;
}
