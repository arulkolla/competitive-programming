#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

void solve() {
    int s, spent = 0;
    cin >> s;
    while (s > 9) {
        spent += (s - s%10);
        s += (s - s%10)/10 - (s - s%10);
    }
    spent += s;
    cout << spent;
}

int main() {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        solve();
        cout << endl;
    }
}
