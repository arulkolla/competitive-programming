#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string s, t;
    cin >> s;
    cin >> t;
    std::reverse(s.begin(), s.end());
    if (s == t) {cout << "YES"; return 0;}
    else {cout << "NO"; return 0;}
}
