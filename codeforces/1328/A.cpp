#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    int t, a, b;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        cin >> a >> b;
        if (a % b == 0) {cout << 0 << endl;}
        else {cout << (b - (a % b)) << endl;}
    }
    return 0;
}
