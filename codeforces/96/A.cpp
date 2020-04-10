#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    int c0 = 0, c1 = 0;
    for (char c : s) {
        if (c == '0') { c0++; c1 = 0; }
        if (c == '1') { c1++; c0 = 0; }
        if ((c0 >= 7) || (c1 >= 7)) {cout << "YES"; return 0;}
    }
    cout << "NO";
    return 0;
}
