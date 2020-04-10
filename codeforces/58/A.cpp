#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    char hello[] = {'h', 'e', 'l', 'l', 'o'};
    int tracker = 0;
    for (char c : s) {
        if (c == hello[tracker]) {tracker += 1;}
        if (tracker >= 5) {cout << "YES"; return 0;}
    }
    cout << "NO";
    return 0;
}
