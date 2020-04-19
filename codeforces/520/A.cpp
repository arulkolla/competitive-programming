#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q[26] = {};
    char c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c;
        c = tolower(c);
        if (q[(int) c - (int) 'a'] == 0) {q[(int) c - (int) 'a'] = 1;}
    }
    for (int i = 0; i < 26; i++) {
        if (q[i] == 0) {cout << "NO"; return 0;}
    }
    cout << "YES";
    return 0;
}