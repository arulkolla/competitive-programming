#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, a, b, c, sa = 0, sb = 0, sc = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        sa += a; sb += b; sc += c;
    }
    ((sa == 0) && (sb == 0) && (sc == 0)) ? (cout << "YES") : (cout << "NO");
    return 0;
}
