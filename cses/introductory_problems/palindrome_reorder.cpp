#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main() {
    string s, sol = "", comb = "", result = "";
    int n, numOdd = 0, arr[26] = {0};
    cin >> s;
    n = s.length();
    for(int i = 0; i < n; i++) {
        arr[s.at(i) - 'A']++;
    }
    for(int i = 0; i < 26; i++) {
        if(arr[i] != 0 && arr[i] % 2 == 1) numOdd++;
    }
    if((n % 2 == 0 && numOdd > 0) || (n % 2 == 1 && numOdd > 1)) {
        cout << "NO SOLUTION" << "\n";
        return 0;
    }
    for(int i = 0; i < 26; i++) {
        if(arr[i] != 0 && arr[i] % 2 == 0) {
            sol.append(arr[i] / 2, (char) (i + 65));
        } else if(arr[i] % 2 == 1)
            comb.append(arr[i], (char) (i + 65));
    }
    string osol = sol;
    reverse(sol.begin(), sol.end());
    result = osol + comb + sol;
    cout << result << "\n";
    return 0;
}
