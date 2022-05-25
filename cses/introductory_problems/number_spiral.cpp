#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main() {
    ll t, rows, cols;
    cin >> t;
    for(int i = 0 ; i < t; i++) {
        cin >> rows >> cols;
        if(rows == 1 && cols == 1){
            cout << 1 << "\n";
            continue;
        }
        if(rows > cols) {
            if(rows % 2 == 0) {
                cout << rows * rows - cols + 1 << "\n";
            } else {
                cout << (rows-1) * (rows-1) + cols << "\n";
            }
        } else {
            if(cols % 2 == 0) {
                cout << (cols-1) * (cols-1) + rows << "\n";
            } else {
                cout << cols * cols - rows + 1 << "\n";
            }
        }
    }
    return 0;
}
