#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<string> permutations;
    do {
        permutations.push_back(s);
    } while(next_permutation(s.begin(), s.end()));
    cout << permutations.size() << "\n";
    for(int i = 0; i < permutations.size(); i++) cout << permutations[i] << "\n";
    return 0;
}
