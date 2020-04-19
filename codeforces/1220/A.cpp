#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int zero = 0, one = 0;
    cin >> n;
    char c[n];
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        if (c[i] == 'z') {
            zero++;
        }
        if (c[i] == 'n') {
            one++;
        }
    }
    for (int i = 0; i < one; i++) {
        cout << 1 << " ";
    }
    for (int i = 0; i < zero; i++) {
        cout << 0 << " ";
    }
}