#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <regex>

using namespace std;

int main() {
    int n, t;
    string s;
    cin >> n >> t;
    cin >> s;
    for (int i = 0; i < t; i++) {
        s = std::regex_replace(s, std::regex("BG"), "GB");
    }
    cout << s;
}
