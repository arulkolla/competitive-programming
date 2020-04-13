#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    string s = "";
    char c = 'a';
    int counter = 0;
    for (int i = 0; i < n; i++) {
        s.push_back(c);
        if (counter+1 < b) {c = static_cast<char>(c+1); counter++;}
        else {c = 'a'; counter = 0;}
    }
    cout << s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    for (int i = 1; i <= tt; i++) {
        solve();
        cout << endl;
    }
}
