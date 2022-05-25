#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main() {
    int msf = 0, sol = 0;
    char c = '\0';
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == c) {
            msf++;
        } else {
            msf = 1;
            c = s[i];
        }
        sol = max(msf, sol);
    }
    cout << sol << endl;
    return 0;
}
