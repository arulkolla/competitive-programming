#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, res = 0;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        switch (s[0]) {
            case 'T':
                res += 4;
                break;
            case 'C':
                res += 6;
                break;
            case 'O':
                res += 8;
                break;
            case 'D':
                res += 12;
                break;
            case 'I':
                res += 20;
                break;
            default:
                return 15;
        }
    
    }
    cout << res;
    return 0;
}